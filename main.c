#include "raylib.h"
#include "game.h"

int main(void)
{
    InitWindow(800, 600, "Snake Game");
    SetTargetFPS(60);

    GameState gameState;
    InitGame(&gameState);

    float moveTimer = 0.0f;
    const float moveDelay = 0.15f;

    while (!WindowShouldClose())
    {
        moveTimer += GetFrameTime();

        if (!gameState.gameOver)
        {
            // Arrow keys
            if ((IsKeyPressed(KEY_UP) || IsKeyPressedRepeat(KEY_UP)) &&
                gameState.snake.direction.y == 0)
            {
                gameState.snake.direction = (Vector2){0, -20};
            }
            else if ((IsKeyPressed(KEY_DOWN) || IsKeyPressedRepeat(KEY_DOWN)) &&
                     gameState.snake.direction.y == 0)
            {
                gameState.snake.direction = (Vector2){0, 20};
            }
            else if ((IsKeyPressed(KEY_LEFT) || IsKeyPressedRepeat(KEY_LEFT)) &&
                     gameState.snake.direction.x == 0)
            {
                gameState.snake.direction = (Vector2){-20, 0};
            }
            else if ((IsKeyPressed(KEY_RIGHT) || IsKeyPressedRepeat(KEY_RIGHT)) &&
                     gameState.snake.direction.x == 0)
            {
                gameState.snake.direction = (Vector2){20, 0};
            }

            // Optional WASD too
            if ((IsKeyPressed(KEY_W) || IsKeyPressedRepeat(KEY_W)) &&
                gameState.snake.direction.y == 0)
            {
                gameState.snake.direction = (Vector2){0, -20};
            }
            else if ((IsKeyPressed(KEY_S) || IsKeyPressedRepeat(KEY_S)) &&
                     gameState.snake.direction.y == 0)
            {
                gameState.snake.direction = (Vector2){0, 20};
            }
            else if ((IsKeyPressed(KEY_A) || IsKeyPressedRepeat(KEY_A)) &&
                     gameState.snake.direction.x == 0)
            {
                gameState.snake.direction = (Vector2){-20, 0};
            }
            else if ((IsKeyPressed(KEY_D) || IsKeyPressedRepeat(KEY_D)) &&
                     gameState.snake.direction.x == 0)
            {
                gameState.snake.direction = (Vector2){20, 0};
            }

            if (moveTimer >= moveDelay)
            {
                UpdateGame(&gameState);
                moveTimer = 0.0f;
            }
        }
        else if (IsKeyPressed(KEY_R))
        {
            CloseGame(&gameState);
            InitGame(&gameState);
            moveTimer = 0.0f;
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawGame(&gameState);

        // Debug: shows current direction
        DrawText(TextFormat("Dir: %.0f, %.0f",
                            gameState.snake.direction.x,
                            gameState.snake.direction.y),
                 10, 40, 20, BLUE);

        EndDrawing();
    }

    CloseGame(&gameState);
    CloseWindow();
    return 0;
}