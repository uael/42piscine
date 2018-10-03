#include <iostream>
#include "Zombie.hpp"

zob::Zombie::Zombie(const std::string &name, const std::string &type)
	: name(name), type(type) {
	std::cout << "<" << name << " (" << type << ")> up !" << std::endl;
}

zob::Zombie::~Zombie() {
	std::cout << "<" << name << " (" << type << ")> down." << std::endl;
}

void zob::Zombie::announce() const {
	std::cout << "<" << name << " (" << type << ")> Braiiiiiiinnnssss..."
	          << std::endl;
}
