#include "Weapon.hpp"

zob::Weapon::Weapon(const std::string &type) : type(type) { }

const std::string &zob::Weapon::getType() const {
	return type;
}

void zob::Weapon::setType(const std::string &type) {
	Weapon::type = type;
}
