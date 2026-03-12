#pragma once

#include "App/AppContext.h"
#include "APP/IApp.h"

class App : public IApp
{
public:
	App();
	virtual ~App() {}

	DISALLOW_COPY_AND_ASSIGN(App);

	virtual Result<void> OnStartup(const AppContext& appCtx) override;
	virtual void OnPreTick(const AppContext& appCtx, float deltaSeconds) override;
	virtual void OnTick(const AppContext& appCtx, float deltaSeconds) override;
	virtual void OnPostTick(const AppContext& appCtx, float deltaSeconds) override;
	virtual void OnRender(const AppContext& appCtx) override;
	virtual Result<void> OnShutdown(const AppContext& appCtx) override;
};