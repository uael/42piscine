#include <iostream>
#include "HumanB.hpp"

zob::HumanB::HumanB(const std::string &name) : name(
	name), weapon() { }

void zob::HumanB::setWeapon(zob::Weapon &weapon) {
	HumanB::weapon = &weapon;
}

void zob::HumanB::attack() const {
	std::cout << name << " attacks with his "
	          << weapon->getType() << "." << std::endl;
}
