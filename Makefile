CC=g++
CFLAGS=-Wall -Wextra -g -std=c++17 

SRC_DIR=src
BIN_DIR=bin

SRC=$(wildcard $(SRC_DIR)/*.cpp)
OBJS=$(patsubst $(SRC_DIR)/%.cpp,$(BIN_DIR)/%.o,$(SRC))

CPPFLAGS=-I$(SRC_DIR)

all: googledino

googledino: $(OBJS)
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $(BIN_DIR)/googledino $^ -lSDL2 -lSDL2_image

$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

clean:
	rm -f $(BIN_DIR)/*.o $(BIN_DIR)/googledino

.PHONY: all clean