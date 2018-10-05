#include <iostream>
#include "ScavTrap.hpp"

zob::ScavTrap::ScavTrap(const std::string &name)
	: ClapTrap(100, 100, 50, 50, 1, name, "SC4V-TP ", 20, 15, 3) {
	std::cout << "SC4V-TP " << name << " up !" << std::endl;
}

zob::ScavTrap::ScavTrap(const zob::ScavTrap &other)
	: ClapTrap(other) {
	std::cout << "SC4V-TP " << name << " up !" << std::endl;
}

zob::ScavTrap::~ScavTrap() {
	std::cout << "SC4V-TP " << name << " down .. arghhhh " << std::endl;
}

zob::ScavTrap &zob::ScavTrap::operator=(zob::ScavTrap other) {
	((zob::ClapTrap)*this) = other;
	return *this;
}


void zob::ScavTrap::challengeNewcomer() {
	if (energyPoints < 12) {
		std::cout << "SC4V-TP " << name
		          << ": Not enough energy." << std::endl;
		return;
	}

	static std::string c[] = {
		"Woow",
		"Hummm, Woow",
		"Haa, Hummm, Woow",
		"Ho! Haa, Hummm, Woow",
		"Hihi, Ho! Haa, Hummm, Woow",
	};

	energyPoints -= 12;

	std::cout << "SC4V-TP " << name
	          << " challenge accepted ! "
	          << c[rand() % 4] << std::endl;
}
