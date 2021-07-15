#include "register.hpp"

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

//explicit template declaration for stupido compilator to know what to do...
template class util::obj_register<sf::Drawable>;