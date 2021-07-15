#include "scene.hpp"
#include "preinitregs.hpp"
scene::scene(){
    preinitregs::regscene(*this);
}
