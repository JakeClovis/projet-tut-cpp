LIBS=-lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio

all: compile bomberman
%.o: src/%.cpp
	g++ -Wall -std=c++11 -c $< -o output/$@
compile:
	@echo "** Compilation de Bomberman"
	@mkdir -p output
bomberman: main.o
	g++ -o bomberman output/* $(LIBS)
clean:
	@echo "** Nettoyage de la compilation"
	rm -f bomberman
	rm -rf output/
