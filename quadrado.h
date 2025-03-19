#ifndef QUADRADO_H
#define QUADRADO_H

#include <SFML/Graphics.hpp>
#include <string>

class Quadrado
{

    int dimX, dimY, posicaoX, posicaoY;

    sf::RectangleShape* quadrado;

public:

    Quadrado(const int dimX, const int dimY, int posicaoX, int posicaoY);

    void movimento(const double velocidade);

    sf::RectangleShape getQuadrado();

    void colorir(const std::string cor);

    void setBorda();

    ~Quadrado();

};

#endif // QUADRADO_H
