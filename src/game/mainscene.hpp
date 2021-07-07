#pragma once
#include "../scene.hpp"
namespace sf{
class Event;
}

class mainscene: public scene
{
private:
    /* data */
public:
    void input(sf::Event&) override;
    void update(double) override;
    mainscene(/* args */);
    ~mainscene();
};

