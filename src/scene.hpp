#pragma once
#include <SFML/Window/Event.hpp>
class scene
{
public:
    virtual void input(sf::Event&) = 0;
    virtual void update(double sec) =0;
};