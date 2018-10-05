#include <iostream>
#include "NinjaTrap.hpp"

zob::NinjaTrap::NinjaTrap(const std::string &name)
	: ClapTrap(60, 60, 120, 120, 1, name, "NINJ4-TP ", 60, 5, 0) {
	std::cout << "NINJ4-TP " << name << " up !" << std::endl;
}

zob::NinjaTrap::NinjaTrap(const zob::NinjaTrap &other)
	: ClapTrap(other) {
	std::cout << "NINJ4-TP " << name << " up !" << std::endl;
}

zob::NinjaTrap::~NinjaTrap() {
	std::cout << "NINJ4-TP " << name << " down .. arghhhh " << std::endl;
}

zob::NinjaTrap &zob::NinjaTrap::operator=(zob::NinjaTrap other) {
	((zob::ClapTrap)*this) = other;
	return *this;
}

void zob::NinjaTrap::ninjaShoebox(zob::FragTrap const &target) {
	if (energyPoints < 12) {
		std::cout << "NINJ4-TP " << name
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

	std::cout << "NINJ4-TP " << name
	          << " here we go FR4G ! " << target.getName() << " "
	          << c[rand() % 4] << std::endl;
}

void zob::NinjaTrap::ninjaShoebox(zob::ScavTrap const &target) {
	if (energyPoints < 12) {
		std::cout << "NINJ4-TP " << name
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

	std::cout << "NINJ4-TP " << name
	          << " here we go SC4V ! " << target.getName() << " "
	          << c[rand() % 4] << std::endl;
}

void zob::NinjaTrap::ninjaShoebox(zob::NinjaTrap const &target) {
	if (energyPoints < 12) {
		std::cout << "NINJ4-TP " << name
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

	std::cout << "NINJ4-TP " << name
	          << " here we go NINJ4 ! " << target.getName() << " "
	          << c[rand() % 4] << std::endl;
}
