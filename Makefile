CC = gcc
CFLAGS = -Wall -std=c99
LDFLAGS = -lraylib -lm -lpthread -ldl -lrt -lX11

SRC = main.c game.c snake.c food.c utils.c
OBJ = $(SRC:.c=.o)

all: snake_game

snake_game: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -f $(OBJ) snake_game