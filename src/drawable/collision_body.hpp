#pragma once
#include "SFML/System/Mutex.hpp"
class collision_body
{
private:
    sf::Mutex mutex;
    // fragile data lol
public:
    collision_body(/* args */);
    ~collision_body();
};

