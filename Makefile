# Definimos variables
CC = g++
CFLAGS = -c -Wall
LDFLAGS =
INCLUDE_DIR = include
SRC_DIR = src
OBJ_DIR = obj

INCLUDE_FILES := $(wildcard $(INCLUDE_DIR)/*.h)
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp) main.cpp
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))

$(shell mkdir -p $(OBJ_DIR))

principal: $(OBJ_FILES)
	$(CC) $(LDFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(INCLUDE_FILES)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) $< -o $@

clean:
	rm -f $(OBJ_DIR)/*.o principal
