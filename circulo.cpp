#include "circulo.h"

Circulo::Circulo(const int radius, int posicaoX, int posicaoY)
{
    this->radius = radius;
    this->posicaoX = posicaoX;
    this->posicaoY = posicaoY;

    circulo = new sf::CircleShape(static_cast<float>(radius));
    circulo->setPosition(static_cast<float>(posicaoX), static_cast<float>(posicaoY));
}

void Circulo::movimento(const int velocidade)
{
    circulo->setPosition(posicaoX, circulo->getPosition().y + velocidade);

    if (circulo->getPosition().y > 720 + circulo->getRadius())
        circulo->setPosition(posicaoX, -radius);
}

sf::CircleShape Circulo::getCirculo()
{
    return * circulo;
}

void Circulo::colorir(const std::string cor)
{
    if (cor == "vermelho")
        circulo->setFillColor(sf::Color::Red);
}

void Circulo::setBorda()
{
    circulo->setOutlineColor(sf::Color::White);
    circulo->setOutlineThickness(1);
}

Circulo::~Circulo()
{
    delete circulo;
}
