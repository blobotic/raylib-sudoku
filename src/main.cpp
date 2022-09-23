#include "../include/raylib.h"
#include <iostream>
#include "Cell.h"
#include "Grid.h"

int GetLastCharPressed() {
    int prev = -1, ret = -1;
    while (prev != 0) {
        ret = prev;
        prev = GetCharPressed();
    }
    return ret;
}

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 600;
    const int screenHeight = 600;

    int selectedNumber = 1;

    Rectangle player = {400, 280, 40, 40};
    Grid* grid = new Grid(&selectedNumber);

    InitWindow(screenWidth, screenHeight, "sudoku");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        
        // change selected number
        int tmp_char = GetLastCharPressed();
        if (tmp_char >= 48 && tmp_char <= 57) selectedNumber = tmp_char % 48;

        // check mouse click
        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) grid->changeValue(GetMouseX(), GetMouseY(), selectedNumber);

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);
            DrawText(std::to_string(selectedNumber).c_str(), 50, 50, 16, GRAY);

            grid->drawGrid();

        EndDrawing();
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}