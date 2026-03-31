#include "food.h"
#include <stdlib.h>

void InitFood(Food *food)
{
    RespawnFood(food);
}

void RespawnFood(Food *food)
{
    food->position.x = (rand() % 40) * 20;
    food->position.y = (rand() % 30) * 20;
}

void DrawFood(const Food *food)
{
    DrawRectangle(food->position.x, food->position.y, 20, 20, RED);
}
bool CheckFoodCollision(Snake *snake, Food *food)
{
    if (snake->body[0].x == food->position.x &&
        snake->body[0].y == food->position.y)
    {
        return true;
    }
    return false;
}