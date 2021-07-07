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
private:
    std::vector<std::shared_ptr<sf::Drawable> > render_pipe;
public:
    RenderPipe(/* args */);
    void draw(sf::RenderTarget&, sf::RenderStates) const override;
    ~RenderPipe();
};