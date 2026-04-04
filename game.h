#ifndef GAME_H
#define GAME_H

#include <stdbool.h>
#include "snake.h"
#include "food.h"

#define MAX_PARTICLES 100

typedef struct Particle
{
    Vector2 position;
    Vector2 velocity;
    Color color;
    float life;
    float maxLife;
} Particle;

typedef enum GameMode
{
    MENU,
    PLAYING,
    GAME_OVER
} GameMode;

typedef struct GameState
{
    Snake snake;
    Food food;
    int score;
    bool gameOver;
    GameMode mode;
    Particle particles[MAX_PARTICLES];
    int particleCount;
    float scoreFlashTimer;
    float menuBlinkTimer;
    Color bgColor1;
    Color bgColor2;
    int snakeColorIndex;
    int bgColorIndex;
} GameState;

void InitGame(GameState *gameState);
void UpdateGame(GameState *gameState);
void DrawGame(const GameState *gameState);
void CloseGame(GameState *gameState);

#endif