PREF_SRC = ./src/
PREF_OBJ = ./obj/
CC = g++

SRC = $(wildcard $(PREF_SRC)*.cpp)
OBJ = $(patsubst $(PREF_SRC)%.c, $(PREF_OBJ)%.o, $(SRC))
PREF_BIN = ./bin/
TARGET = game
LIBS = -lX11

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) $(LIBS) -o $(PREF_BIN)$(TARGET)

clear:
	rm $(PREF_OBJ)*.o
