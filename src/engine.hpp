#pragma once
#include "SFML/Graphics.hpp"
#include "RenderPipe.hpp"
#include "ScenePipe.hpp"

class engineconstants;

class engine
{
private:
    bool m_break_loop;
    sf::RenderWindow window;
    RenderPipe rd_pipe;
    ScenePipe sc_pipe;
    sf::Clock main_clock;
    /* data */
public:
    void run();
    void run_singe_iter();
    void break_loop();
    sf::RenderWindow& getWindow();
    RenderPipe& getRenderPipe();
    ScenePipe& getScenePipe();
    engine(engineconstants&);
    engine();
    ~engine();
};
