#include "raylib.h"

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 1200;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - keyboard input");

    Vector2 Position = { 80, 80 };
    
    int block[4][4] = {
        {1, 1, 1, 1},  // I 블록
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };

    SetTargetFPS(30);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        if (IsKeyDown(KEY_RIGHT)) Position.x += 20;
        if (IsKeyDown(KEY_LEFT)) Position.x -= 20;
        if (IsKeyDown(KEY_UP)) Position.y -= 20;
        if (IsKeyDown(KEY_DOWN)) Position.y += 20;
        
        if(Position.x < 0) Position.x += 20;
        if(Position.x > 780) Position.x -= 20;
        if(Position.y < 0) Position.y += 20;
        if(Position.y > 1180) Position.y -= 20;
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            for (int x = 0; x < GetScreenWidth(); x += 20) {
                DrawLine(x, 0, x, GetScreenHeight(), LIGHTGRAY);
            }
            for (int y = 0; y < GetScreenHeight(); y += 20) {
                DrawLine(0, y, GetScreenWidth(), y, LIGHTGRAY);
            }       

            DrawText("move the ball with arrow keys", 10, 10, 20, DARKGRAY);

            for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (block[i][j]) {
                    DrawRectangle(Position.x + 20 * j, Position.y + 20 * i, 20, 20, BLUE);
                }
            }
        }

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}