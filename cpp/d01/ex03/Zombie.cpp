#include <iostream>

#include "Zombie.hpp"

zob::Zombie::Zombie() : type("Ultra") {
	std::string t[] = { "Rick", "Carl", "Glen", "Daryl", "Carol", "Eugene" };

	name = t[rand() % 5];
}

zob::Zombie::~Zombie() { }

void zob::Zombie::announce() const {
	std::cout << "<" << name << " (" << type << ")> Braiiiiiiinnnssss..."
	          << std::endl;
}
