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

protected:
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

	void RemoveActor(const std::string& key)
	{
		auto iter = _sceneActorMap.find(key);
		if (iter != _sceneActorMap.end())
		{
			_sceneActorMap.erase(iter);
		}
	}

	void DestroyActor(const std::string& key)
	{
		_actorMgr->DestroyActor(key);
	}

private:
	ActorManager* _actorMgr = nullptr;
	std::map<std::string, IActor*> _sceneActorMap;
};