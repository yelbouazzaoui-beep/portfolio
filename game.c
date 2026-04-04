#include "game.h"
#include "snake.h"
#include "food.h"
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

void InitGame(GameState *gameState)
{
    gameState->score = 0;
    InitSnake(&gameState->snake);
    InitFood(&gameState->food);
    gameState->gameOver = false;
    gameState->mode = MENU;
    gameState->particleCount = 0;
    gameState->scoreFlashTimer = 0.0f;
    gameState->menuBlinkTimer = 0.0f;
    gameState->bgColor1 = DARKBLUE;
    gameState->bgColor2 = (Color){20, 20, 50, 255};
    gameState->snakeColorIndex = 0;
    gameState->bgColorIndex = 0;
}

void AddParticle(GameState *gameState, Vector2 pos, Color color)
{
    if (gameState->particleCount < MAX_PARTICLES)
    {
        Particle *p = &gameState->particles[gameState->particleCount++];
        p->position = pos;
        p->velocity = (Vector2){(float)(rand() % 200 - 100) / 10.0f, (float)(rand() % 200 - 100) / 10.0f};
        p->color = color;
        p->life = 1.0f;
        p->maxLife = 1.0f;
    }
}

void UpdateGame(GameState *gameState)
{
    if (gameState->mode == PLAYING && gameState->gameOver)
        return;

    if (gameState->mode == PLAYING)
    {
        UpdateSnake(&gameState->snake);

        if (CheckFoodCollision(&gameState->snake, &gameState->food))
        {
            gameState->score++;
            GrowSnake(&gameState->snake);
            RespawnFood(&gameState->food);
            gameState->scoreFlashTimer = 0.5f; // Flash for 0.5 seconds
            // Add particles
            for (int i = 0; i < 10; i++)
            {
                AddParticle(gameState, gameState->food.position, YELLOW);
            }
        }

        if (CheckSelfCollision(&gameState->snake) || CheckWallCollision(&gameState->snake))
        {
            gameState->gameOver = true;
            gameState->mode = GAME_OVER;
        }
    }

    // Update particles
    for (int i = 0; i < gameState->particleCount; i++)
    {
        gameState->particles[i].position.x += gameState->particles[i].velocity.x;
        gameState->particles[i].position.y += gameState->particles[i].velocity.y;
        gameState->particles[i].life -= GetFrameTime();
        if (gameState->particles[i].life <= 0)
        {
            // Remove particle
            gameState->particles[i] = gameState->particles[--gameState->particleCount];
            i--;
        }
    }

    // Update score flash
    if (gameState->scoreFlashTimer > 0)
    {
        gameState->scoreFlashTimer -= GetFrameTime();
    }

    // Update menu blink
    gameState->menuBlinkTimer += GetFrameTime();
}

void DrawGame(const GameState *gameState)
{
    if (gameState->mode == MENU)
    {
        DrawText("Snake Game", 300, 200, 40, GREEN);
        if (sinf(gameState->menuBlinkTimer * 5) > 0)
        {
            DrawText("Press SPACE to Start", 280, 300, 20, WHITE);
        }
        DrawText("Press C to Change Snake Color", 240, 340, 18, WHITE);
        DrawText("Press B to Change Background", 240, 370, 18, WHITE);
        DrawText("Use Arrow Keys or WASD to Move", 220, 400, 18, WHITE);
    }
    else if (gameState->mode == PLAYING)
    {
        // Background gradient
        DrawRectangleGradientV(0, 0, 800, 600, gameState->bgColor1, gameState->bgColor2);
        DrawSnake(&gameState->snake);
        DrawFood(&gameState->food);
        Color scoreColor = (gameState->scoreFlashTimer > 0) ? YELLOW : WHITE;
        DrawText(TextFormat("Score: %d", gameState->score), 10, 10, 20, scoreColor);
    }
    else if (gameState->mode == GAME_OVER)
    {
        DrawText("Game Over!", 320, 250, 40, RED);
        DrawText(TextFormat("Final Score: %d", gameState->score), 290, 300, 20, YELLOW);
        DrawText("Press R to Restart or ESC to Quit", 220, 350, 20, WHITE);
    }

    // Draw particles
    for (int i = 0; i < gameState->particleCount; i++)
    {
        Color c = gameState->particles[i].color;
        c.a = (unsigned char)(255 * (gameState->particles[i].life / gameState->particles[i].maxLife));
        DrawRectangle(gameState->particles[i].position.x, gameState->particles[i].position.y, 4, 4, c);
    }
}

void CloseGame(GameState *gameState)
{
    FreeSnake(&gameState->snake);
}