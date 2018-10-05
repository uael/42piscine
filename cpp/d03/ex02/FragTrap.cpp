#include <iostream>
#include "FragTrap.hpp"

zob::FragTrap::FragTrap(const std::string &name)
	: ClapTrap(100, 100, 100, 100, 1, name, "FR4G-TP ", 30, 20, 5) {
	std::cout << "FR4G-TP " << name << " up !" << std::endl;
}

zob::FragTrap::FragTrap(const zob::FragTrap &other)
	: ClapTrap(other) {
	std::cout << "FR4G-TP " << name << " up !" << std::endl;
}

zob::FragTrap::~FragTrap() {
	std::cout << "FR4G-TP " << name << " down .. arghhhh " << std::endl;
}

zob::FragTrap &zob::FragTrap::operator=(zob::FragTrap other) {
	((zob::ClapTrap)*this) = other;
	return *this;
}

void zob::FragTrap::vaulthunter_dot_exe(std::string const &target) {
	if (energyPoints < 25) {
		std::cout << "FR4G-TP " << name
		          << ": Not enough energy, stop using me !" << std::endl;
		return;
	}

	std::string a[] = { "Cheese", "Fireball", "Keyboard", "Pony", "Dart" };

	energyPoints -= 25;

	std::cout << "FR4G-TP " << name
	          << " attacks " << target
	          << " with " << a[rand() % 4]
	          << ", causing " << rand() % 42
	          << " points of damage !" << std::endl;
}
