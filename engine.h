#pragma once

#include "quadrado.h"
#include "circulo.h"

#include <random>

#define MAX 1080
#define VEL_MAX 15
#define VEL_MIN 1

class Engine
{
    sf::RenderWindow * window;

    std::vector<Circulo*> circulos;
    std::vector<Quadrado*> quadrados;
    
    sf::CircleShape * controlado;

    float posicaoXC;
    float posicaoYC;

    bool gameover;

public:
    Engine();

    void play();

    void menu();

    ~Engine();
};
