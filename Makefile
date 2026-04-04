CC = gcc
CFLAGS = -Wall -std=c99
LDFLAGS = -lraylib -lopengl32 -lgdi32 -lwinmm

SRC = game.c main.c snake.c food.c utils.c
OBJ = $(SRC:.c=.o)

all: snake_game

snake_game: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -f $(OBJ) snake_game