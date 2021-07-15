#include "RenderPipe.hpp"
#include <iostream>

void RenderPipe::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    for(const auto & item : reg)
        target.draw(*item);
}

RenderPipe::RenderPipe(/* args */)
{
}

RenderPipe::~RenderPipe()
{
}
