#pragma once
#include <vector>
#include <memory>
#include <iostream>
#include "SFML/Graphics.hpp"

namespace util{
    template <typename T>
    class obj_register
    {
    protected:
        std::vector<std::shared_ptr<T> > reg;
    public:
        void _register(T& item);
        void _unregister(T& item);
    };
}

//class util::obj_register<sf::Drawable>;

//class util::obj_register<sf::Drawable>;