#include <iostream>
#include "ScavTrap.hpp"

zob::ScavTrap::ScavTrap(const std::string &name)
	: hitPoints(100),
	  maxHitPoints(100),
	  energyPoints(50),
	  maxEnergyPoints(50),
	  level(1),
	  name(name),
	  meleeAttackDamage(20),
	  rangedAttackDamage(15),
	  armorDamageReduction(3) {
	std::cout << "SC4V-TP " << name << " up !" << std::endl;
}

zob::ScavTrap::ScavTrap(const zob::ScavTrap &other)
	: hitPoints(other.hitPoints),
	  maxHitPoints(other.maxHitPoints),
	  energyPoints(other.energyPoints),
	  maxEnergyPoints(other.maxEnergyPoints),
	  level(other.level),
	  name(other.name),
	  meleeAttackDamage(other.meleeAttackDamage),
	  rangedAttackDamage(other.rangedAttackDamage),
	  armorDamageReduction(other.armorDamageReduction) {
	std::cout << "SC4V-TP " << name << " up !" << std::endl;
}

zob::ScavTrap::~ScavTrap() {
	std::cout << "SC4V-TP " << name << " down .. arghhhh " << std::endl;
}

zob::ScavTrap &zob::ScavTrap::operator=(zob::ScavTrap other) {
	hitPoints = other.hitPoints;
	maxHitPoints = other.maxHitPoints;
	energyPoints = other.energyPoints;
	maxEnergyPoints = other.maxEnergyPoints;
	level = other.level;
	name = other.name;
	meleeAttackDamage = other.meleeAttackDamage;
	rangedAttackDamage = other.rangedAttackDamage;
	armorDamageReduction = other.armorDamageReduction;
	return *this;
}

void zob::ScavTrap::rangedAttack(std::string const &target) const {
	std::cout << "SC4V-TP " << name
	          << " attacks " << target
	          << " at range, causing " << rangedAttackDamage
	          << " points of damage !" << std::endl;
}

void zob::ScavTrap::meleeAttack(std::string const &target) const {
	std::cout << "SC4V-TP " << name
	          << " attacks " << target
	          << " with his own hands, causing " << meleeAttackDamage
	          << " points of damage !" << std::endl;

}

void zob::ScavTrap::takeDamage(unsigned amount) {
	amount -=
		armorDamageReduction <= amount ? armorDamageReduction : amount;
	hitPoints -= amount <= hitPoints ? amount : hitPoints;

	std::cout << "SC4V-TP " << name
	          << " takes " << amount
	          << " points of damage !" << std::endl;
}

void zob::ScavTrap::beRepaired(unsigned amount) {
	hitPoints += amount;
	if (hitPoints > maxHitPoints)
		hitPoints = maxHitPoints;

	std::cout << "SC4V-TP " << name
	          << " has been repaired " << amount
	          << " hit points !" << std::endl;
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

unsigned int zob::ScavTrap::getHitPoints() const {
	return hitPoints;
}

unsigned int zob::ScavTrap::getMaxHitPoints() const {
	return maxHitPoints;
}

unsigned int zob::ScavTrap::getEnergyPoints() const {
	return energyPoints;
}

unsigned int zob::ScavTrap::getMaxEnergyPoints() const {
	return maxEnergyPoints;
}

unsigned int zob::ScavTrap::getLevel() const {
	return level;
}

const std::string &zob::ScavTrap::getName() const {
	return name;
}

unsigned int zob::ScavTrap::getMeleeAttackDamage() const {
	return meleeAttackDamage;
}

unsigned int zob::ScavTrap::getRangedAttackDamage() const {
	return rangedAttackDamage;
}

unsigned int zob::ScavTrap::getArmorDamageReduction() const {
	return armorDamageReduction;
}

std::ostream &zob::operator<<(std::ostream &os, const zob::ScavTrap &trap) {
	os << "hitPoints: " << trap.getHitPoints() << " maxHitPoints: "
	   << trap.getMaxHitPoints() << " energyPoints: " << trap.getEnergyPoints()
	   << " maxEnergyPoints: " << trap.getMaxEnergyPoints() << " level: "
	   << trap.getLevel()
	   << " name: " << trap.getName() << " meleeAttackDamage: "
	   << trap.getMeleeAttackDamage() << " rangedAttackDamage: "
	   << trap.getRangedAttackDamage() << " armorDamageReduction: "
	   << trap.getArmorDamageReduction();
	return os;
}

