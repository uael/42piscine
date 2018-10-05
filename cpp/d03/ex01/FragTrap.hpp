#ifndef PROJECT_FRAGTRAP_HPP
#define PROJECT_FRAGTRAP_HPP

#include <string>
#include <ostream>

namespace zob {

	class FragTrap {
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
		FragTrap(const std::string &name);

		FragTrap(const FragTrap &other);

		virtual ~FragTrap();

		FragTrap &operator=(FragTrap other);

		void rangedAttack(std::string const &target) const;

		void meleeAttack(std::string const &target) const;

		void takeDamage(unsigned damage);

		void beRepaired(unsigned damage);

		void vaulthunter_dot_exe(std::string const &target);

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

	std::ostream &operator<<(std::ostream &os, const FragTrap &trap);
}

#endif //PROJECT_FRAGTRAP_HPP
