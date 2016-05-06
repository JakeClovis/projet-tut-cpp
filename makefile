LIBS=-lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system
CC=$(CROSS)g++ -c -Wall -std=c++11 $(DEFINES)
SRCS=src/main.cpp\
	 src/Button.cpp\
	 src/Controller.cpp\
	 src/Game.cpp\
	 src/GameWindow.cpp\
	 src/Menu.cpp\
	 src/ResourceAllocator.cpp\
	 src/Tile.cpp\
	 src/Tilemap.cpp\
	 src/Tileset.cpp\
	 src/TileSystem.cpp
OBJ=$(subst src/,output/, $(subst .cpp,.o, $(SRCS)))
all: bomberman
bomberman: $(OBJ)
	g++ -o bomberman output/*.o $(LIBS)
output/%.o: src/%.cpp .d/%.d
	$(CC) $< -o $@
.d/%.d: src/%.cpp
	$(CC) -MM $< -MF $@
clean:
	rm -f output/*.o
	rm bomberman

-include $(OBJECTS:%.o=.d/%.d)
-include $(LOBJECTS:%.o=.d/%.d)
