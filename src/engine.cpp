#include "engine.hpp"
#include "engineconstants.hpp"

void engine::run(){
	while(window.isOpen() and not m_break_loop)
		run_singe_iter();
}

void engine::run_singe_iter(){
	sf::Event ev;
	while(window.pollEvent(ev)){
		sc_pipe.input(ev);
        if(ev.type == sf::Event::Closed)
            window.close();
        }
	sc_pipe.update(main_clock.restart().asSeconds());
	window.clear();
	window.draw(rd_pipe);
}

sf::RenderWindow& engine::getWindow()	{   return window;	}
RenderPipe& engine::getRenderPipe()	{	return rd_pipe;	}
ScenePipe& engine::getScenePipe()	{	return sc_pipe;	}

void engine::break_loop(){
    m_break_loop = true;
}
engine::engine(engineconstants& constants):
m_break_loop(false),
window(sf::VideoMode(constants.wind_width,constants.wind_heigh),constants.wind_name.c_str())
{}

engine::engine():
m_break_loop(false),
window(sf::VideoMode(1920,720),"app")
{}

engine::~engine()
{}
