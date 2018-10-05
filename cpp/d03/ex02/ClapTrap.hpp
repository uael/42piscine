#ifndef PROJECT_CLAPTRAP_HPP
#define PROJECT_CLAPTRAP_HPP

#include <string>
#include <ostream>

namespace zob {

	class ClapTrap {
	protected:
		unsigned hitPoints,
			maxHitPoints,
			energyPoints,
			maxEnergyPoints,
			level;
		std::string name, dg;
		unsigned meleeAttackDamage,
			rangedAttackDamage,
			armorDamageReduction;
	public:
		ClapTrap(unsigned int hitPoints, unsigned int maxHitPoints,
		         unsigned int energyPoints, unsigned int maxEnergyPoints,
		         unsigned int level, const std::string &name,
		         const std::string &dg,
		         unsigned int meleeAttackDamage, unsigned int rangedAttackDamage,
		         unsigned int armorDamageReduction);

		ClapTrap(const ClapTrap &other);

		virtual ~ClapTrap();

		ClapTrap &operator=(ClapTrap other);

		void rangedAttack(std::string const &target) const;

		void meleeAttack(std::string const &target) const;

		void takeDamage(unsigned damage);

		void beRepaired(unsigned damage);

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

	std::ostream &operator<<(std::ostream &os, const ClapTrap &trap);
}

#endif //PROJECT_CLAPTRAP_HPP
