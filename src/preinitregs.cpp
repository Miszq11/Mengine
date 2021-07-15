#include "preinitregs.hpp"
#include <iostream>

RenderPipe preinitregs::rd_pipe;
ScenePipe preinitregs::sc_pipe;

preinitregs::preinitregs(/* args */) {}
preinitregs::~preinitregs() {}

void preinitregs::regdrawable(sf::Drawable& it) { rd_pipe._register(it); }
void preinitregs::regscene(scene& it) { sc_pipe._register(it); }
RenderPipe& preinitregs::getrd_pipe() {
    return rd_pipe; 
    }
ScenePipe& preinitregs::getsc_pipe() {
    return sc_pipe; 
    }