#ifndef GAME_H
#define GAME_H

#include <stdbool.h>
#include "snake.h"
#include "food.h"

typedef struct GameState
{
    Snake snake;
    Food food;
    int score;
    bool gameOver;
} GameState;

void InitGame(GameState *gameState);
void UpdateGame(GameState *gameState);
void DrawGame(const GameState *gameState);
void CloseGame(GameState *gameState);

#endif