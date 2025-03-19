#include "quadrado.h"

Quadrado::Quadrado(const int dimX, const int dimY, int posicaoX, int posicaoY)
{
    this->dimX = dimX;
    this->dimY = dimY;
    this->posicaoX = posicaoX;
    this->posicaoY = posicaoY;

    quadrado = new sf::RectangleShape({static_cast<float>(dimX), static_cast<float>(dimY)});
    quadrado->setPosition(posicaoX, posicaoY);
}

Quadrado::~Quadrado()
{
    delete quadrado;
}

void Quadrado::movimento(const double velocidade)
{
    quadrado->setPosition(posicaoX, quadrado->getPosition().y + velocidade);

    if (quadrado->getPosition().y > 720 + quadrado->getSize().y)
        quadrado->setPosition(posicaoX, -dimY);

}

void Quadrado::setBorda()
{
    quadrado->setOutlineColor(sf::Color::White);
    quadrado->setOutlineThickness(1);
}

sf::RectangleShape Quadrado::getQuadrado()
{
    return * quadrado;
}

void Quadrado::colorir(const std::string cor)
{
    if (cor == "azul")
        quadrado->setFillColor(sf::Color::Blue);
}