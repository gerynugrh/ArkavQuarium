# Masukkan semua file cpp Anda
OBJS = src/SilverCoin.cpp src/Piranha.cpp src/Helper.cpp src/main.cpp src/Animation.cpp src/NormalSnail.cpp src/NormalFood.cpp src/Game.cpp src/Guppy.cpp src/Position.cpp src/Fish.cpp src/AquariumObject.cpp src/Aquarium.cpp

CC = g++
COMPILER_FLAGS = -std=c++11 -Wall -O2 -g
LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf
OBJ_NAME = out/oopquarium
all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
