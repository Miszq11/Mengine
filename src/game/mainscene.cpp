#include "mainscene.hpp"
#include "SFML/Graphics.hpp"
#include "../preinitregs.hpp"

void mainscene::input(sf::Event& ev){
    if(ev.type == sf::Event::KeyPressed){
        if(ev.key.code == sf::Keyboard::A || ev.key.code == sf::Keyboard::Left){
            dx += dx==0?-speed:0;}
        if(ev.key.code == sf::Keyboard::D || ev.key.code == sf::Keyboard::Right)
            dx += dx==0?speed:0;
        if(ev.key.code == sf::Keyboard::W || ev.key.code == sf::Keyboard::Up)
            dy += dy==0?-speed:0;
        if(ev.key.code == sf::Keyboard::S || ev.key.code == sf::Keyboard::Down)
            dy += dy==0?speed:0;
    }
    if(ev.type == sf::Event::KeyReleased){
        if(ev.key.code == sf::Keyboard::A || ev.key.code == sf::Keyboard::Left
            || ev.key.code == sf::Keyboard::D || ev.key.code == sf::Keyboard::Right)
                dx=0;
        if(ev.key.code == sf::Keyboard::W || ev.key.code == sf::Keyboard::Up
            || ev.key.code == sf::Keyboard::S || ev.key.code == sf::Keyboard::Down)
                dy=0;
    }
}

void mainscene::update(double sec){
    shape.move(((double)dx)*sec,((double)dy)*sec);
}

mainscene::mainscene(/* args */): shape(20),dx(0), dy(0), speed(100.f)
{
    std::cout<<"mainscene const\n";
    preinitregs::regdrawable(shape);
    shape.setPosition(500,500);
    shape.setFillColor(sf::Color::Blue);
    std::cout<<"shape mainscene at: "<< &shape<<std::endl;
}

mainscene::~mainscene()
{
    std::cout<<"mainscene dest\n";
}