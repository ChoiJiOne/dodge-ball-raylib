#pragma once

#include <map>

#include "Actor/IActor.h"
#include "Manager/ActorManager.h"

class IScene
{
public:
	IScene() : _actorMgr(ActorManager::GetPtr()) {}
	virtual ~IScene() { _actorMgr = nullptr; }

	DISALLOW_COPY_AND_ASSIGN(IScene);

	virtual Result<void> OnEnter() = 0;
	virtual Result<void> OnExit() = 0;

	const std::map<std::string, IActor*>& GetSceneActorMap() const { return _sceneActorMap; }

	template <typename TActor, typename... Args>
	Result<void> CreateAndAddActor(const std::string& key, Args&&... args)
	{
		Result<TActor*> result = _actorMgr->CreateActor<TActor>(key, std::forward<Args>(args)...);
		if (!result.IsSuccess())
		{
			return Result<void>::Fail(result.GetError());
		}

		_sceneActorMap.emplace(key, result.GetValue());
		return Result<void>::Success();
	}

	// WARN: 이거 외부에서 _sceneActorMap 루프 돌면서 호출하면 안됨. 반드시 하나의 액터에 대해서만 호출해야 함.
	void RemoveAndDestroyActor(const std::string& key)
	{
		auto iter = _sceneActorMap.find(key);
		if (iter != _sceneActorMap.end())
		{
			_sceneActorMap.erase(iter);
		}

		_actorMgr->DestroyActor(key);
	}

	template <typename TActor>
	Result<TActor*> GetActor(const std::string& key)
	{
		auto iter = _sceneActorMap.find(key);
		if (iter == _sceneActorMap.end())
		{
			return Result<TActor*>::Fail(MAKE_ERROR(
				EErrorCode::NOT_FOUND_ACTOR,
				std::format("NOT_FOUND_ACTOR:{0}", key)
			));
		}

		TActor* actorPtr = reinterpret_cast<TActor*>(iter->second.get());
		return Result<TActor*>::Success(actorPtr);
	}

protected:
	void ClearActorMap()
	{
		const auto& sceneActorMap = GetSceneActorMap();
		for (const auto& [key, sceneActor] : _sceneActorMap)
		{
			_actorMgr->DestroyActor(key);
		}

		_sceneActorMap.clear();
	}

private:
	ActorManager* _actorMgr = nullptr;
	std::map<std::string, IActor*> _sceneActorMap;
};