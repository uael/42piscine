#include <iostream>

#include "ZombieEvent.hpp"

static void randomChump(zob::ZombieEvent const &ze) {
	zob::Zombie *z;
	std::string t[] = { "Rick", "Carl", "Glen", "Daryl", "Carol", "Eugene" };

	z = ze.newZombie(t[rand() % 5]);
	z->announce();
	delete z;
}

int main() {
	zob::ZombieEvent ze = zob::ZombieEvent("Basic");
	char i;

	srand(static_cast<unsigned int>(time(nullptr)));
	std::cout << std::endl;

	for (i = 0; i < 9; i++) randomChump(ze), std::cout << std::endl;
	ze.setZombieType("Ultra");
	for (i = 0; i < 9; i++) randomChump(ze), std::cout << std::endl;

	return 0;
}