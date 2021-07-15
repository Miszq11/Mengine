#include "engine.hpp"
#include "engineconstants.hpp"
#include "preinitregs.hpp"

void engine::run(){
	while(window.isOpen() and not m_break_loop)
		run_singe_iter();
}
static int iter = 0;
void engine::run_singe_iter(){
	sf::Event ev;
	while(window.pollEvent(ev)){
		sc_pipe.input(ev);
        if(ev.type == sf::Event::Closed)
            window.close();
		}
	double esttime = main_clock.restart().asMicroseconds();
	if(iter++ > 100){
		//std::cout<<" est time: "<< esttime << std::endl;
		iter=0;
	}
	sc_pipe.update(esttime/1000000.f);
	window.clear();
	window.draw(rd_pipe);
	window.display();
}

sf::RenderWindow& engine::getWindow()	{   return window;	}
RenderPipe& engine::getRenderPipe()	{	return rd_pipe;	}
ScenePipe& engine::getScenePipe()	{	return sc_pipe;	}

void engine::break_loop(){
    m_break_loop = true;
}
engine::engine(engineconstants& constants):
m_break_loop(false),
window(sf::VideoMode(constants.wind_width,constants.wind_heigh),constants.wind_name.c_str()),
rd_pipe(preinitregs::getrd_pipe()),
sc_pipe(preinitregs::getsc_pipe())
{
	init();
}

engine::engine():
m_break_loop(false),
window(sf::VideoMode(1080,720),"app"),
rd_pipe(preinitregs::getrd_pipe()),
sc_pipe(preinitregs::getsc_pipe())
{
	init();
    std::cout<<"engineregs render at: "<<&rd_pipe<<std::endl;
    std::cout<<"engineregs scene at: "<<&sc_pipe<<std::endl;
}

void engine::init(){
	//window.setFramerateLimit(120);
	//window.setVerticalSyncEnabled(true);
	window.setKeyRepeatEnabled(false);
}

engine::~engine()
{}
