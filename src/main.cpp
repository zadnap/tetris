#include "raylib.h"

int main()
{
    // Initialize window
    const int screenWidth = 800;
    const int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "Simple Raylib Animation");

    // Ball variables
    Vector2 ballPosition = {screenWidth / 2.0f, screenHeight / 2.0f};
    Vector2 ballSpeed = {4.0f, 3.0f};
    float ballRadius = 20.0f;

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        // Update ball position
        ballPosition.x += ballSpeed.x;
        ballPosition.y += ballSpeed.y;

        // Bounce off walls
        if (ballPosition.x - ballRadius <= 0 || ballPosition.x + ballRadius >= screenWidth)
        {
            ballSpeed.x *= -1;
        }
        if (ballPosition.y - ballRadius <= 0 || ballPosition.y + ballRadius >= screenHeight)
        {
            ballSpeed.y *= -1;
        }

        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawCircleV(ballPosition, ballRadius, RED);
        DrawText("Bouncing Ball Animation", 10, 10, 20, DARKGRAY);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
