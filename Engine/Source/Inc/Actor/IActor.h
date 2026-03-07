#pragma once

#include "Macro/Macro.h"

class IActor
{
public:
	IActor() = default;
	virtual ~IActor() = default;

	DISALLOW_COPY_AND_ASSIGN(IActor);

	virtual void Tick(float deltaSeconds) = 0;
	virtual void Release() = 0;

	bool IsInitialized() { return _isInitialized; }

protected:
	bool _isInitialized = false;
};

//#pragma once
//
//#include <map>
//#include <string>
//#include <memory>
//#include <typeinfo>
//
//#include "Macro/Macro.h"
//#include "Actor/IActorModel.h"
//#include "Actor/IActorController.h"
//
//class IActor
//{
//public:
//	IActor() = default;
//	virtual ~IActor() = default;
//
//	DISALLOW_COPY_AND_ASSIGN(IActor);
//
//	virtual void Tick(float deltaSeconds)
//	{
//		// 1. 등록된 모든 컨트롤러들의 Tick을 호출해 줍니다.
//		for (auto& [key, controller] : _controllers)
//		{
//			if (controller)
//			{
//				controller->Tick(deltaSeconds);
//			}
//		}
//	}
//
//	virtual void Release()
//	{
//		// 컴포넌트들 자원 해제
//		for (auto& [key, controller] : _controllers)
//		{
//			if (controller) controller->Release();
//		}
//
//		_controllers.clear();
//		_models.clear();
//	}
//
//	bool IsInitialized() const { return _isInitialized; }
//
//	// ============================================
//	// Model 관리
//	// ============================================
//	template<typename TModel, typename... Args>
//	void AddModel(Args&&... args)
//	{
//		std::string typeName = typeid(TModel).name();
//		_models[typeName] = std::make_unique<TModel>(std::forward<Args>(args)...);
//	}
//
//	template<typename TModel>
//	TModel* GetModel() const
//	{
//		std::string typeName = typeid(TModel).name();
//		auto iter = _models.find(typeName);
//		if (iter != _models.end())
//		{
//			return static_cast<TModel*>(iter->second.get());
//		}
//		return nullptr;
//	}
//
//	// ============================================
//	// Controller 관리
//	// ============================================
//	template<typename TController, typename... Args>
//	void AddController(Args&&... args)
//	{
//		std::string typeName = typeid(TController).name();
//		auto controller = std::make_unique<TController>(std::forward<Args>(args)...);
//
//		// 소유자 등록 (Initialize)
//		controller->Initialize(this);
//
//		_controllers[typeName] = std::move(controller);
//	}
//
//	template<typename TController>
//	TController* GetController() const
//	{
//		std::string typeName = typeid(TController).name();
//		auto iter = _controllers.find(typeName);
//		if (iter != _controllers.end())
//		{
//			return static_cast<TController*>(iter->second.get());
//		}
//		return nullptr;
//	}
//
//protected:
//	bool _isInitialized = false;
//
//private:
//	// TypeName을 키로 삼아 모델과 컨트롤러들을 보관
//	std::map<std::string, std::unique_ptr<IActorModel>> _models;
//	std::map<std::string, std::unique_ptr<IActorController>> _controllers;
//};
