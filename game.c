#include "game.h"
#include "snake.h"
#include "food.h"
#include <stdlib.h>
#include <stdbool.h>

void InitGame(GameState *gameState)
{
    gameState->score = 0;
    InitSnake(&gameState->snake);
    InitFood(&gameState->food);
    gameState->gameOver = false;
}

void UpdateGame(GameState *gameState)
{
    if (gameState->gameOver)
        return;

    UpdateSnake(&gameState->snake);

    if (CheckFoodCollision(&gameState->snake, &gameState->food))
    {
        gameState->score++;
        GrowSnake(&gameState->snake);
        RespawnFood(&gameState->food);
    }

    if (CheckSelfCollision(&gameState->snake) || CheckWallCollision(&gameState->snake))
    {
        gameState->gameOver = true;
    }
}

void DrawGame(const GameState *gameState)
{
    if (gameState->gameOver)
    {
        DrawText("Game Over! Press R to Restart", 200, 300, 20, RED);
        return;
    }

    DrawSnake(&gameState->snake);
    DrawFood(&gameState->food);
    DrawText(TextFormat("Score: %d", gameState->score), 10, 10, 20, BLACK);
}

void CloseGame(GameState *gameState)
{
    FreeSnake(&gameState->snake);
}