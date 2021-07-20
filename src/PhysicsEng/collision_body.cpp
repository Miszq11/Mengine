#include "collision_body.hpp"

physics_body::~physics_body() {}

physics_body::physics_body(sf::Sprite& sprt, bool isstatic){

}

physics_body::physics_body(sf::Shape& sprt, bool isstatic){

}

void default_phys_fun(double time){

}

void default_phys_fun_static(double time){

}


template<typename T>
collision_obj<T>::collision_obj(T& obj, bool (*col_fun)(T& obj1, T& obj2)):
Obj(&obj, [](T*)->void{}){
    //obj = std::shared_ptr<T>( &obj, [](T*)->void{});
    collision_fun = col_fun;
}

template<typename T>
bool collision_obj<T>::pixel_prfct(T& obj2){
    return collision_fun(*Obj,obj2);
}

template class collision_obj<sf::Sprite>;