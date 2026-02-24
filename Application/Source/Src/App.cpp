#include <raylib.h>

#include "App.h"

App::App() 
{
}

Result<void> App::OnStartup(const AppContext& appCtx)
{
	return Result<void>::Success();
}

void App::OnPreTick(const AppContext& appCtx, float deltaSeconds)
{
	InputManager* inputMgr = appCtx.GetInputManager();
	if (inputMgr->GetKeyPress(EKey::ESCAPE) == EPress::PRESSED)
		appCtx.RequestQuit();
}

void App::OnTick(const AppContext& appCtx, float deltaSeconds)
{
	for (auto& actor : _actors)
		actor->Tick(deltaSeconds);
}

void App::OnPostTick(const AppContext& appCtx, float deltaSeconds)
{
}

void App::OnRender(const AppContext& appCtx)
{
	BeginDrawing();
	{
		ClearBackground(RAYWHITE);
		DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
	}
	EndDrawing();
}

Result<void> App::OnShutdown(const AppContext& appCtx)
{
	return Result<void>::Success();
}