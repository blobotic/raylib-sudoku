#include "../include/raylib.h"
#include <iostream>
#include "Cell.h"
#include "Grid.h"

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 600;
    const int screenHeight = 600;

    Rectangle player = {400, 280, 40, 40};
    Grid* grid = new Grid();

    InitWindow(screenWidth, screenHeight, "sudoku");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) player.x += 2;
        // if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) player.x -= 2;
        // if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) player.y -= 2;
        // if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) player.y += 2;

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            // DrawRectangleRec(player, MAROON);

            grid->drawGrid();

        EndDrawing();
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}