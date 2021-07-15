#pragma once
#include "RenderPipe.hpp"
#include "ScenePipe.hpp"

namespace sf{
	class Drawable;
}
class scene;

class preinitregs
{
private:
	static RenderPipe rd_pipe;
	static ScenePipe sc_pipe;
public:
	static void regdrawable(sf::Drawable&);
	static void regscene(scene&);
	preinitregs(/* args */);
	~preinitregs();
};
