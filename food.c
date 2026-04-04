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
    DrawRectangle(food->position.x + 2, food->position.y + 2, 20, 20, (Color){0, 0, 0, 100});
    DrawRectangle(food->position.x, food->position.y, 20, 20, YELLOW);
}
bool CheckFoodCollision(Snake *snake, Food *food)
{
    if (snake->targetBody[0].x == food->position.x &&
        snake->targetBody[0].y == food->position.y)
    {
        return true;
    }
    return false;
}