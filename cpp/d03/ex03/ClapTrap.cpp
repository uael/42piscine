#include <iostream>
#include "ClapTrap.hpp"

zob::ClapTrap::ClapTrap(unsigned int hitPoints, unsigned int maxHitPoints,
                        unsigned int energyPoints, unsigned int maxEnergyPoints,
                        unsigned int level, const std::string &name,
                        const std::string &dg,
                        unsigned int meleeAttackDamage,
                        unsigned int rangedAttackDamage,
                        unsigned int armorDamageReduction)
	: hitPoints(hitPoints),
	  maxHitPoints(maxHitPoints),
	  energyPoints(energyPoints),
	  maxEnergyPoints(maxEnergyPoints),
	  level(level),
	  name(name),
	  dg(dg),
	  meleeAttackDamage(meleeAttackDamage),
	  rangedAttackDamage(rangedAttackDamage),
	  armorDamageReduction(armorDamageReduction) {
	std::cout << "CL4P-TP " << name << " up !" << std::endl;
}

zob::ClapTrap::ClapTrap(const zob::ClapTrap &other)
	: hitPoints(other.hitPoints),
	  maxHitPoints(other.maxHitPoints),
	  energyPoints(other.energyPoints),
	  maxEnergyPoints(other.maxEnergyPoints),
	  level(other.level),
	  name(other.name),
	  meleeAttackDamage(other.meleeAttackDamage),
	  rangedAttackDamage(other.rangedAttackDamage),
	  armorDamageReduction(other.armorDamageReduction) {
	std::cout << "CL4P-TP " << name << " up !" << std::endl;
}

zob::ClapTrap::~ClapTrap() {
	std::cout << "CL4P-TP " << name << " down .. arghhhh " << std::endl;
}

zob::ClapTrap &zob::ClapTrap::operator=(zob::ClapTrap other) {
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

void zob::ClapTrap::rangedAttack(std::string const &target) const {
	std::cout << dg << name
	          << " attacks " << target
	          << " at range, causing " << rangedAttackDamage
	          << " points of damage !" << std::endl;
}

void zob::ClapTrap::meleeAttack(std::string const &target) const {
	std::cout << dg << name
	          << " attacks " << target
	          << " with his own hands, causing " << meleeAttackDamage
	          << " points of damage !" << std::endl;

}

void zob::ClapTrap::takeDamage(unsigned amount) {
	amount -=
		armorDamageReduction <= amount ? armorDamageReduction : amount;
	hitPoints -= amount <= hitPoints ? amount : hitPoints;

	std::cout << dg << name
	          << " takes " << amount
	          << " points of damage !" << std::endl;
}

void zob::ClapTrap::beRepaired(unsigned amount) {
	hitPoints += amount;
	if (hitPoints > maxHitPoints)
		hitPoints = maxHitPoints;

	std::cout << dg << name
	          << " has been repaired " << amount
	          << " hit points !" << std::endl;
}

unsigned int zob::ClapTrap::getHitPoints() const {
	return hitPoints;
}

unsigned int zob::ClapTrap::getMaxHitPoints() const {
	return maxHitPoints;
}

unsigned int zob::ClapTrap::getEnergyPoints() const {
	return energyPoints;
}

unsigned int zob::ClapTrap::getMaxEnergyPoints() const {
	return maxEnergyPoints;
}

unsigned int zob::ClapTrap::getLevel() const {
	return level;
}

const std::string &zob::ClapTrap::getName() const {
	return name;
}

unsigned int zob::ClapTrap::getMeleeAttackDamage() const {
	return meleeAttackDamage;
}

unsigned int zob::ClapTrap::getRangedAttackDamage() const {
	return rangedAttackDamage;
}

unsigned int zob::ClapTrap::getArmorDamageReduction() const {
	return armorDamageReduction;
}

std::ostream &zob::operator<<(std::ostream &os, const zob::ClapTrap &trap) {
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
