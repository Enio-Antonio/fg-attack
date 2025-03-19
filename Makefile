main: main.cpp engine.cpp quadrado.cpp circulo.cpp
	g++ main.cpp engine.cpp quadrado.cpp circulo.cpp -Ofast -o main -lsfml-graphics -lsfml-window -lsfml-system