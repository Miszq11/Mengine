#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "register.hpp"
#include <algorithm>
#include <iostream>
#include <memory>

//class util::obj_register<sf::Drawable>;

class RenderPipe:public sf::Drawable, public util::obj_register<sf::Drawable>
{
public:
    RenderPipe(/* args */);
    void draw(sf::RenderTarget&, sf::RenderStates) const override;
    ~RenderPipe();
};