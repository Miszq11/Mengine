#pragma once
#include "../scene.hpp"
#include "SFML/Graphics.hpp"
namespace sf{
class Event;
}

class mainscene: public scene
{
private:
    sf::CircleShape shape;
    int dx,dy;
    float speed;
    /* data */
public:
    void input(sf::Event&) override;
    void update(double) override;
    mainscene(/* args */);
    ~mainscene();
};

