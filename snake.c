#include "snake.h"
#include <stdlib.h>

void InitSnake(Snake *snake)
{
    snake->length = 3; // Initial length of the snake
    snake->body = malloc(snake->length * sizeof(Vector2));

    // Set the snake's initial position at the center of the screen
    for (int i = 0; i < snake->length; i++)
    {
        snake->body[i] = (Vector2){400 - i * 20, 300}; // Aligned on a 20-pixel grid
    }

    snake->direction = (Vector2){20, 0}; // Moving right initially
}

void UpdateSnake(Snake *snake)
{
    if (snake->direction.x == 0 && snake->direction.y == 0)
        return; // Prevent movement if direction is (0, 0)

    // Shift the body segments
    for (int i = snake->length - 1; i > 0; i--)
    {
        snake->body[i] = snake->body[i - 1];
    }

    // Update the head position based on the direction
    snake->body[0].x += snake->direction.x;
    snake->body[0].y += snake->direction.y;
}

bool CheckSelfCollision(const Snake *snake)
{
    // Start checking from index 1 to avoid comparing the head with itself
    for (int i = 1; i < snake->length; i++)
    {
        if (snake->body[0].x == snake->body[i].x && snake->body[0].y == snake->body[i].y)
        {
            return true;
        }
    }
    return false;
}

bool CheckWallCollision(const Snake *snake)
{
    // Check if the snake's head is outside the screen bounds
    return snake->body[0].x < 0 || snake->body[0].x >= 800 || snake->body[0].y < 0 || snake->body[0].y >= 600;
}

void DrawSnake(const Snake *snake)
{
    for (int i = 0; i < snake->length; i++)
    {
        DrawRectangle(snake->body[i].x, snake->body[i].y, 20, 20, GREEN);
    }
}

void FreeSnake(Snake *snake)
{
    free(snake->body);
}
void GrowSnake(Snake *snake)
{
    snake->length++;

    snake->body = realloc(snake->body, snake->length * sizeof(Vector2));

    // copy last segment
    snake->body[snake->length - 1] = snake->body[snake->length - 2];
}