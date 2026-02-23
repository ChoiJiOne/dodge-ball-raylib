//#include "AppHost.h"
//#include "App.h"
//
//int main(int argc, char* argv[])
//{
//	AppHost appHost;
//	App app;
//
//	// CHECKME: 여기 main 엔트리 포인트 이후에 점검 필요
//	Result<void> result = appHost.Startup();
//	if (!result.IsSuccess())
//	{
//		return 0; // NOTE: 여기에 뭔가 로그라도 찍어줘야 하지 않을까...?
//	}
//
//	result = appHost.Run(app);
//	if (!result.IsSuccess())
//	{
//		return 0; // NOTE: 여기에 뭔가 로그라도 찍어줘야 하지 않을까...?
//	}
//
//	result = appHost.Shutdown();
//	if (!result.IsSuccess())
//	{
//		return 0; // NOTE: 여기에 뭔가 로그라도 찍어줘야 하지 않을까...?
//	}
//
//	return 0;
//}


#include <raylib.h>

int main(void)
{
	// Initialization
	//--------------------------------------------------------------------------------------
	const int screenWidth = 800;
	const int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

	SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		// TODO: Update your variables here
		//----------------------------------------------------------------------------------

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(RAYWHITE);

		DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}