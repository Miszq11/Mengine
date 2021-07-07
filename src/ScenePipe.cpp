#include "ScenePipe.hpp"
void ScenePipe::input(sf::Event& ev){
    for(const auto& item : reg)
        (*item).input(ev);
}
void ScenePipe::update(double sec){
    for(const auto& item : reg)
        (*item).update(sec);
}

ScenePipe::ScenePipe(/* args */)
{
}

ScenePipe::~ScenePipe()
{
}
