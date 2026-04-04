#include "snake.h"
#include <stdlib.h>
#include "raymath.h"

void InitSnake(Snake *snake)
{
    snake->length = 3; // Initial length of the snake
    snake->body = malloc(snake->length * sizeof(Vector2));
    snake->targetBody = malloc(snake->length * sizeof(Vector2));

    // Set the snake's initial position at the center of the screen
    for (int i = 0; i < snake->length; i++)
    {
        snake->body[i] = (Vector2){400 - i * 20, 300}; // Aligned on a 20-pixel grid
        snake->targetBody[i] = snake->body[i];
    }

    snake->direction = (Vector2){20, 0}; // Moving right initially
    snake->lerpTimer = 0.0f;
    snake->bodyColor = GREEN;
    snake->headColor = LIME;
    snake->eyeColor = DARKGREEN;
}

void UpdateSnake(Snake *snake)
{
    if (snake->direction.x == 0 && snake->direction.y == 0)
        return; // Prevent movement if direction is (0, 0)

    // If not lerping, set new targets
    if (snake->lerpTimer >= 0.06f) // moveDelay
    {
        // Shift the target body segments
        for (int i = snake->length - 1; i > 0; i--)
        {
            snake->targetBody[i] = snake->targetBody[i - 1];
        }

        // Update the head target position based on the direction
        snake->targetBody[0].x += snake->direction.x;
        snake->targetBody[0].y += snake->direction.y;

        snake->lerpTimer = 0.0f;
    }

    // Lerp towards targets
    float t = snake->lerpTimer / 0.06f;
    if (t > 1.0f)
        t = 1.0f;
    for (int i = 0; i < snake->length; i++)
    {
        snake->body[i].x = Lerp(snake->body[i].x, snake->targetBody[i].x, t);
        snake->body[i].y = Lerp(snake->body[i].y, snake->targetBody[i].y, t);
    }

    snake->lerpTimer += GetFrameTime();
}

bool CheckSelfCollision(const Snake *snake)
{
    // Start checking from index 1 to avoid comparing the head with itself
    for (int i = 1; i < snake->length; i++)
    {
        if (snake->targetBody[0].x == snake->targetBody[i].x && snake->targetBody[0].y == snake->targetBody[i].y)
        {
            return true;
        }
    }
    return false;
}

bool CheckWallCollision(const Snake *snake)
{
    // Check if the snake's head is outside the screen bounds
    return snake->targetBody[0].x < 0 || snake->targetBody[0].x >= 800 || snake->targetBody[0].y < 0 || snake->targetBody[0].y >= 600;
}

void DrawSnake(const Snake *snake)
{
    for (int i = 0; i < snake->length; i++)
    {
        // Shadow
        DrawRectangle(snake->body[i].x + 2, snake->body[i].y + 2, 20, 20, (Color){0, 0, 0, 100});
        Color color = (i == 0) ? snake->headColor : snake->bodyColor;
        DrawRectangle(snake->body[i].x, snake->body[i].y, 20, 20, color);
    }

    // Draw eyes on head
    Vector2 head = snake->body[0];
    DrawCircle(head.x + 5, head.y + 5, 3, snake->eyeColor);
    DrawCircle(head.x + 15, head.y + 5, 3, snake->eyeColor);
}

void FreeSnake(Snake *snake)
{
    free(snake->body);
    free(snake->targetBody);
}
void GrowSnake(Snake *snake)
{
    snake->length++;

    snake->body = realloc(snake->body, snake->length * sizeof(Vector2));
    snake->targetBody = realloc(snake->targetBody, snake->length * sizeof(Vector2));

    // copy last segment
    snake->body[snake->length - 1] = snake->body[snake->length - 2];
    snake->targetBody[snake->length - 1] = snake->targetBody[snake->length - 2];
}