#include "Weapon.hpp"

const std::string& Weapon::getType() {
    const std::string&   ref = type;
    return (ref);
}

void    Weapon::setType(std::string new_type) {
    this->type = new_type;
}

Weapon::Weapon (std::string new_type) {
    setType(new_type);
}
