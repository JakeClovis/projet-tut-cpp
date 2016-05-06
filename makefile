LIBS=-lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system
all: compile bomberman
%.o: src/%.cpp
	@echo "* Compilation de $@"
	g++ -Wall -std=c++11 -c $< -o output/$@
compile:
	@echo "** Compilation de Bomberman"
	@mkdir -p output
bomberman: main.o ResourceAllocator.o Controller.o Game.o GameWindow.o Tile.o Tileset.o TileSystem.o Tilemap.o Menu.o Button.o
	@echo "* Assemblage"
	g++ -o bomberman output/* $(LIBS)
clean:
	@echo "** Nettoyage de la compilation"
	rm -f bomberman
	rm -rf output/
