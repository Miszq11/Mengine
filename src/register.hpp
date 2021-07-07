#pragma once
#include <vector>
#include <memory>
#include <iostream>
#include "SFML/Graphics.hpp"

namespace util{
    template <typename T>
    class obj_register
    {
    protected:
        std::vector<std::shared_ptr<T> > reg;
    public:
        void _register(T& item);
        void _unregister(T& item);
    };
}
template<typename T>
void util::obj_register<T>::_register(T& item){
    reg.push_back(
        std::shared_ptr<T>(
            &item, 
            [](T*)->void{}));
}
template<typename T>
void util::obj_register<T>::_unregister(T& item_arg){
    auto item = std::shared_ptr<T>(&item_arg,[](T*)->void{});
    const typename std::vector<std::shared_ptr<T>>::iterator item_f = std::find(reg.begin(),reg.end(),item);
    if(item_f == reg.end()){
        std::cerr<<"no item found"<<std::endl;
        return;
    }
    reg.erase(item_f);
}

//class util::obj_register<sf::Drawable>;