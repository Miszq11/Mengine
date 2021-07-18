#include "collision_body.hpp"

physics_body::physics_body(/* args */){}

physics_body::~physics_body() {}

template<typename T>
collision_obj<T>::collision_obj(T& obj, bool (*col_fun)(T& obj1, T& obj2)){
    obj = std::shared_ptr<T>( &obj, [](T*)->void{});
    collision_fun = col_fun;
}

template<typename T>
bool collision_obj<T>::pixel_prfct(T& obj2){
    return collision_fun(*Obj,obj2);
}