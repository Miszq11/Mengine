#include "scene.hpp"
#include "register.hpp"
#include <vector>
#include <memory>
#pragma once
class ScenePipe:public util::obj_register<scene>
{
public:
    void input(sf::Event&);
    void update(double sec);
    ScenePipe(/* args */);
    ~ScenePipe();
};