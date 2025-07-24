//
// Created by haimash on 7/24/25.
//

#include "Player.h"
#include <raylib.h>

int main()
{
    InitWindow(640, 480, "super_mario_like");
    SetTargetFPS(60);

    Player player;
    if (false == player.Init({100, 100}, {32, 32}))
    {
        return 1; // Init failed
    }

    Rectangle ground = { 0, 400, 800, 80 };

    while (false == WindowShouldClose())
    {
        player.Update();

        if (CheckCollisionRecs(player.GetRect(), ground))
        {
            player.OnGroundCollision(ground.y);
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawRectangleRec(ground, DARKGRAY);
        player.Draw();

        EndDrawing();
    }

    CloseWindow();

    return 0;
};