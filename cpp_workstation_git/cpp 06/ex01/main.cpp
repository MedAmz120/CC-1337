#include "Serializer.hpp"

int main() {
    Data data;
    data.v = 10;
    // Serializer serializer;

    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Serializer: " << raw << std::endl;
    
    Data* deserializedData = Serializer::deserialize(raw);
    std::cout << "DeSerializer: " << deserializedData << std::endl;
    return 0;
}