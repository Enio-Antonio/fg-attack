#ifndef CIRCULO_H
#define CIRCULO_H

#include <SFML/Graphics.hpp>

class Circulo
{
    int radius;
    int posicaoX, posicaoY;

    sf::CircleShape * circulo;

public:
    Circulo(const int radius, int posicaoX, int posicaoY);

    void movimento(const int velocidade);

    sf::CircleShape getCirculo();

    void colorir(const std::string cor);

    void setBorda();

    ~Circulo();
};

#endif // CIRCULO_H
