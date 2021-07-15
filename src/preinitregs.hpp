#pragma once
#include "RenderPipe.hpp"
#include "ScenePipe.hpp"

namespace sf{
	class Drawable;
}
class scene;

class preinitregs
{
protected:
	static RenderPipe rd_pipe;
	static ScenePipe sc_pipe;
public:
	static void regdrawable(sf::Drawable&);
	static void regscene(scene&);
	static RenderPipe& getrd_pipe();
	static ScenePipe& getsc_pipe();
	preinitregs(/* args */);
	~preinitregs();
};
