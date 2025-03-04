#include "../raylib/include/raylib.h"
#include "scheduler.h"
#include "player.h"
#include <stdio.h>

int main()
{
    CommandScheduler scheduler;
    Player player(&scheduler);

    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "T2480");

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        scheduler.periodic();

        EndDrawing();
    }
    CloseWindow();
}