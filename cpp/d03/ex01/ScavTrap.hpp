#ifndef PROJECT_SCAVTRAP_HPP
#define PROJECT_SCAVTRAP_HPP

#include <string>
#include <ostream>

namespace zob {

	class ScavTrap {
	private:
		unsigned hitPoints,
			maxHitPoints,
			energyPoints,
			maxEnergyPoints,
			level;
		std::string name;
		unsigned meleeAttackDamage,
			rangedAttackDamage,
			armorDamageReduction;
	public:
		ScavTrap(const std::string &name);

		ScavTrap(const ScavTrap &other);

		virtual ~ScavTrap();

		ScavTrap &operator=(ScavTrap other);

		void rangedAttack(std::string const &target) const;

		void meleeAttack(std::string const &target) const;

		void takeDamage(unsigned damage);

		void beRepaired(unsigned damage);

		void challengeNewcomer();

		unsigned int getHitPoints() const;

		unsigned int getMaxHitPoints() const;

		unsigned int getEnergyPoints() const;

		unsigned int getMaxEnergyPoints() const;

		unsigned int getLevel() const;

		const std::string &getName() const;

		unsigned int getMeleeAttackDamage() const;

		unsigned int getRangedAttackDamage() const;

		unsigned int getArmorDamageReduction() const;
	};

	std::ostream &operator<<(std::ostream &os, const ScavTrap &trap);
}

#endif //PROJECT_SCAVTRAP_HPP
