#include "engine.h"
#include <iostream>

Engine::Engine()
{
    // Números aleatórios
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib_x(0, MAX);
    std::uniform_int_distribution<> distrib_y(25, 30);

    window = new sf::RenderWindow(sf::VideoMode(1080, 720), "FGG");
    window->setFramerateLimit(30);

    int distancia = 0;

    for (int i = 0; i < 5; i++)
    {
        quadrados.push_back(new Quadrado(50, 100, distancia, distrib_y(gen)));
        distancia += 200;
    }
    for (auto i = 0; i < quadrados.size(); i++)
    {
        quadrados[i]->colorir("azul");
        quadrados[i]->setBorda();
    }

    distancia = 90;

    for (int i = 0; i < 5; i++)
    {
        circulos.push_back(new Circulo(50, distancia, distrib_y(gen)));
        distancia += 200;
    }
    for (auto i = 0; i < quadrados.size(); i++)
    {
        circulos[i]->colorir("vermelho");
        circulos[i]->setBorda();
    }

    posicaoXC = 510.f;
    posicaoYC = 650.f;

    controlado = new sf::CircleShape(20.f);
    controlado->setPosition(posicaoXC, posicaoYC);
    controlado->setFillColor(sf::Color::White);

    gameover = false;
};

Engine::~Engine()
{
    delete window;
    delete controlado;
};

void Engine::play()
{
    while (window->isOpen())
    {
        for (auto event = sf::Event{}; window->pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                window->close();
            }
        }

        if (!gameover)
        {
            for (auto i = 0; i < quadrados.size(); i++)
            {
                //quadrados[i]->movimento((std::rand() % (VEL_MAX - VEL_MIN + 1) + VEL_MIN) + i);
                //int velocidade_dentro_do_for = (std::rand() % (VEL_MAX - VEL_MIN + 1) + VEL_MIN) + i;
                quadrados[i]->getQuadrado().move(0.f, 10.f);
            }

            for (auto i = 0; i < circulos.size(); i++)
            {
                circulos[i]->movimento(std::rand() % (VEL_MAX - VEL_MIN + 1) + VEL_MIN);
            }

            // Controle
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && controlado->getPosition().y > 0)
            {
                controlado->setPosition(controlado->getPosition().x, controlado->getPosition().y - 10);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && controlado->getPosition().y < 680)
            {
                controlado->setPosition(controlado->getPosition().x, controlado->getPosition().y + 10);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) && controlado->getPosition().x > 0)
            {
                controlado->setPosition(controlado->getPosition().x - 10, controlado->getPosition().y);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) && controlado->getPosition().x < 1040)
            {
                controlado->setPosition(controlado->getPosition().x + 10, controlado->getPosition().y);
            }

            // Colisão
            for (auto i = 0; i < quadrados.size(); i++)
            {
                if (controlado->getGlobalBounds().intersects(quadrados[i]->getQuadrado().getGlobalBounds()))
                {
                    gameover = true;
                }
                if (controlado->getGlobalBounds().intersects(circulos[i]->getCirculo().getGlobalBounds()))
                {
                    gameover = true;
                }
            }

            window->clear();

            for (auto i = 0; i < quadrados.size(); i++)
            {
                window->draw(quadrados[i]->getQuadrado());
            }
            for (auto i = 0; i < circulos.size(); i++)
            {
                window->draw(circulos[i]->getCirculo());
            }

            window->draw(*controlado);

            window->display();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            quadrados.clear();
            circulos.clear();
            
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> distrib_x(0, MAX);
            std::uniform_int_distribution<> distrib_y(25, 30);

            int distancia = 0;

            for (int i = 0; i < 5; i++)
            {
                quadrados.push_back(new Quadrado(50, 100, distancia, distrib_y(gen)));
                distancia += 200;
            }
            for (auto i = 0; i < quadrados.size(); i++)
            {
                quadrados[i]->colorir("azul");
                quadrados[i]->setBorda();
            }

            distancia = 90;

            for (int i = 0; i < 5; i++)
            {
                circulos.push_back(new Circulo(50, distancia, distrib_y(gen)));
                distancia += 200;
            }
            for (auto i = 0; i < quadrados.size(); i++)
            {
                circulos[i]->colorir("vermelho");
                circulos[i]->setBorda();
            }

            controlado->setPosition(posicaoXC, posicaoYC);

            gameover = false;
        }
    }
}