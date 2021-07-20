#pragma once
#include "SFML/System/Mutex.hpp"
#include "SFML/Graphics.hpp"

class physics_body
{
private:
    sf::Mutex mutex;
    // fragile data lol
    bool isstatic;
protected:
    void (*phys_fun)(double elapsed_time);
public:
    //non-mutex members
    
    //mutex members
    void physic_run(double elapsed_time);
    physics_body(sf::Sprite& sprt, bool isstatic = false);
    physics_body(sf::Shape& sprt, bool isstatic = false);
    ~physics_body();
};

void default_phys_fun_rigid(double time);
void default_phys_fun_static(double time);

#include <memory>
template<typename T>
class collision_obj{
private:
    std::shared_ptr<T> Obj;
    bool (* collision_fun)(T& obj1, T& obj2);
public:
    collision_obj() = delete;
    collision_obj(T& obj, bool (*col_fun)(T& obj1, T& obj2));
    bool pixel_prfct(T& obj2);
};