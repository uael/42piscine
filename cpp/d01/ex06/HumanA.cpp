#include <iostream>
#include "HumanA.hpp"

zob::HumanA::HumanA(const std::string &name, zob::Weapon &weapon) : name(
	name), weapon(&weapon) { }

void zob::HumanA::attack() const {
	std::cout << name << " attacks with his "
	          << weapon->getType() << "." << std::endl;
}
