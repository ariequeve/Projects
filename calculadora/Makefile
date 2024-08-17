# Makefile en el directorio principal de calculadora/

CC = gcc
CFLAGS = -Wall
SRC = src/main.c src/operaciones.c
OBJ = main

all: $(OBJ)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -o $(OBJ) $(SRC)

clean:
	rm -f $(OBJ)
