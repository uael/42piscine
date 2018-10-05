#include <iostream>
#include "FragTrap.hpp"

zob::FragTrap::FragTrap(const std::string &name)
	: hitPoints(100),
	  maxHitPoints(100),
	  energyPoints(100),
	  maxEnergyPoints(100),
	  level(1),
	  name(name),
	  meleeAttackDamage(30),
	  rangedAttackDamage(30),
	  armorDamageReduction(5) {
	std::cout << "FR4G-TP " << name << " up !" << std::endl;
}

zob::FragTrap::FragTrap(const zob::FragTrap &other)
	: hitPoints(other.hitPoints),
	  maxHitPoints(other.maxHitPoints),
	  energyPoints(other.energyPoints),
	  maxEnergyPoints(other.maxEnergyPoints),
	  level(other.level),
	  name(other.name),
	  meleeAttackDamage(other.meleeAttackDamage),
	  rangedAttackDamage(other.rangedAttackDamage),
	  armorDamageReduction(other.armorDamageReduction) {
	std::cout << "FR4G-TP " << name << " up !" << std::endl;
}

zob::FragTrap::~FragTrap() {
	std::cout << "FR4G-TP " << name << " down .. arghhhh " << std::endl;
}

zob::FragTrap &zob::FragTrap::operator=(zob::FragTrap other) {
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

void zob::FragTrap::rangedAttack(std::string const &target) const {
	std::cout << "FR4G-TP " << name
	          << " attacks " << target
	          << " at range, causing " << rangedAttackDamage
	          << " points of damage !" << std::endl;
}

void zob::FragTrap::meleeAttack(std::string const &target) const {
	std::cout << "FR4G-TP " << name
	          << " attacks " << target
	          << " with his own hands, causing " << meleeAttackDamage
	          << " points of damage !" << std::endl;

}

void zob::FragTrap::takeDamage(unsigned amount) {
	amount -=
		armorDamageReduction <= amount ? armorDamageReduction : amount;
	hitPoints -= amount <= hitPoints ? amount : hitPoints;

	std::cout << "FR4G-TP " << name
	          << " takes " << amount
	          << " points of damage !" << std::endl;
}

void zob::FragTrap::beRepaired(unsigned amount) {
	hitPoints += amount;
	if (hitPoints > maxHitPoints)
		hitPoints = maxHitPoints;

	std::cout << "FR4G-TP " << name
	          << " has been repaired " << amount
	          << " hit points !" << std::endl;
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

unsigned int zob::FragTrap::getHitPoints() const {
	return hitPoints;
}

unsigned int zob::FragTrap::getMaxHitPoints() const {
	return maxHitPoints;
}

unsigned int zob::FragTrap::getEnergyPoints() const {
	return energyPoints;
}

unsigned int zob::FragTrap::getMaxEnergyPoints() const {
	return maxEnergyPoints;
}

unsigned int zob::FragTrap::getLevel() const {
	return level;
}

const std::string &zob::FragTrap::getName() const {
	return name;
}

unsigned int zob::FragTrap::getMeleeAttackDamage() const {
	return meleeAttackDamage;
}

unsigned int zob::FragTrap::getRangedAttackDamage() const {
	return rangedAttackDamage;
}

unsigned int zob::FragTrap::getArmorDamageReduction() const {
	return armorDamageReduction;
}

std::ostream &zob::operator<<(std::ostream &os, const zob::FragTrap &trap) {
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

