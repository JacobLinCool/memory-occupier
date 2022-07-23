CC = gcc
FLAGS = -Wall -Wextra -Werror -std=c99

all: build

build: mo

mo: src/memory_occupier.c
	@$(CC) $(FLAGS) -o mo src/memory_occupier.c
	@echo "Compiled!"
