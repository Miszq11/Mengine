#include "SFML/Graphics.hpp"
#include "src/RenderPipe.hpp"
#include "src/ScenePipe.hpp"
#include "src/game/mainscene.hpp"
#include "src/engine.hpp"
#include <iostream>

int main(){
    sf::RenderWindow window(sf::VideoMode(500,500),"oknooooo");
    RenderPipe g;
    engine eng;
    sf::CircleShape cir(50.f);
    cir.setFillColor(sf::Color::Blue);

    int dx=1, dy=1, x=50, y=50;

    g._register(cir);

    while(window.isOpen()){
        sf::Event ev;
        while(window.pollEvent(ev)){
            if(ev.type ==sf::Event::Closed)
                window.close();
            if(ev.type == sf::Event::KeyPressed)
                if(ev.key.code == sf::Keyboard::Q)
                    window.close();
        }
        window.clear();
        cir.setPosition(x,y);
        
        if(x<0 or x>window.getSize().x)
            dx *=-1;
        if(y<0 or y>window.getSize().y)
            dy *=-1;
        x+=dx,y+=dy;
        
        window.draw(g);
        window.display();
    }
}