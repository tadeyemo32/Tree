CC = clang
CFLAGS = -Wall -std=c99
SRC = main.c node.c queue.c
OUT = main

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Linux)
    LIBS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
endif

ifeq ($(UNAME_S),Darwin)
    CFLAGS += -I/opt/homebrew/include
    LDFLAGS = -L/opt/homebrew/lib
    LIBS = -lraylib -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo
endif

ifeq ($(OS),Windows_NT)
    CC = gcc
    CFLAGS += -I./raylib/include
    LDFLAGS = -L./raylib/lib
    LIBS = -lraylib -lopengl32 -lgdi32 -lwinmm
    OUT := main.exe
endif

$(OUT): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(OUT) $(LDFLAGS) $(LIBS)

clean:
	rm -f $(OUT)
