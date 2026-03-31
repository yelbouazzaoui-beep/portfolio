#ifndef FOOD_H
#define FOOD_H

#include "raylib.h"
#include "snake.h"

typedef struct Food
{
    Vector2 position;
} Food;

void InitFood(Food *food);
void RespawnFood(Food *food);
void DrawFood(const Food *food);

bool CheckFoodCollision(Snake *snake, Food *food);
#endif