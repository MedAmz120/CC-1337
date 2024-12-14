#include "Serializer.hpp"

Serializer::Serializer()
{
}

Serializer::Serializer(Serializer &copie)
{
    *this = copie;
}
uintptr_t Serializer::serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
    Data* data = new Data();
    data->v = raw;
    return data;
}