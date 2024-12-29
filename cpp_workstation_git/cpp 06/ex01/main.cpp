#include "Serializer.hpp"

int main() {
    Data* ptr = NULL;
    Data* new_ptr = NULL;
    uintptr_t raw;

    ptr = new Data;
    ptr->str = "Lorem ipsum";

    raw = Serializer::serialize(ptr);    
    
    new_ptr = Serializer::deserialize(raw);
    
    std::cout << "Data of ptr: " << ptr->str << std::endl;
    std::cout << "Data of new_ptr: " << new_ptr->str << std::endl;

    delete ptr;

    return 0;
}