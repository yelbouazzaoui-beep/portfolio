#include "raylib.h"
#include "game.h"

int main(void)
{
    InitWindow(800, 600, "Snake Game");
    SetTargetFPS(60);

    GameState gameState;
    InitGame(&gameState);

    const Color snakeBodyColors[] = {GREEN, ORANGE, SKYBLUE, RED};
    const Color snakeHeadColors[] = {LIME, (Color){255, 165, 0, 255}, SKYBLUE, (Color){255, 0, 0, 255}};
    const Color snakeEyeColors[] = {DARKGREEN, (Color){139, 69, 19, 255}, DARKBLUE, (Color){139, 0, 0, 255}};
    const Color bgColors1[] = {DARKBLUE, BLACK, DARKGRAY};
    const Color bgColors2[] = {(Color){20, 20, 50, 255}, BLACK, DARKGRAY};

    float moveTimer = 0.0f;
    const float moveDelay = 0.06f; // Even faster snake speed: move every 0.06 seconds

    while (!WindowShouldClose())
    {
        moveTimer += GetFrameTime();

        if (gameState.mode == MENU)
        {
            if (IsKeyPressed(KEY_SPACE))
            {
                gameState.mode = PLAYING;
            }
            if (IsKeyPressed(KEY_C))
            {
                gameState.snakeColorIndex = (gameState.snakeColorIndex + 1) % 4;
                gameState.snake.bodyColor = snakeBodyColors[gameState.snakeColorIndex];
                gameState.snake.headColor = snakeHeadColors[gameState.snakeColorIndex];
                gameState.snake.eyeColor = snakeEyeColors[gameState.snakeColorIndex];
            }
            if (IsKeyPressed(KEY_B))
            {
                gameState.bgColorIndex = (gameState.bgColorIndex + 1) % 3;
                gameState.bgColor1 = bgColors1[gameState.bgColorIndex];
                gameState.bgColor2 = bgColors2[gameState.bgColorIndex];
            }
        }
        else if (gameState.mode == PLAYING)
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
        else if (gameState.mode == GAME_OVER)
        {
            if (IsKeyPressed(KEY_R))
            {
                CloseGame(&gameState);
                InitGame(&gameState);
                moveTimer = 0.0f;
            }
        }

        BeginDrawing();
        ClearBackground(DARKBLUE);
        DrawGame(&gameState);

        // Debug: shows current direction
        if (gameState.mode == PLAYING)
        {
            DrawText(TextFormat("Dir: %.0f, %.0f",
                                gameState.snake.direction.x,
                                gameState.snake.direction.y),
                     10, 40, 20, GREEN);
        }

        EndDrawing();
    }

    CloseGame(&gameState);
    CloseWindow();
    return 0;
}