#pragma once
#include "SFML/System/Mutex.hpp"
class physics_body
{
private:
    sf::Mutex mutex;
    // fragile data lol
public:
    //non-mutex members
    
    //mutex members
    
    
    physics_body(/* args */);
    ~physics_body();
};

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