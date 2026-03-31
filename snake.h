#ifndef SNAKE_H
#define SNAKE_H

#include "raylib.h"

typedef struct Snake
{
    Vector2 *body;
    int length;
    Vector2 direction;
} Snake;

void InitSnake(Snake *snake);
void UpdateSnake(Snake *snake);
void GrowSnake(Snake *snake);
bool CheckSelfCollision(const Snake *snake);
bool CheckWallCollision(const Snake *snake);
void DrawSnake(const Snake *snake);
void FreeSnake(Snake *snake);

#endif