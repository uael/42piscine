#ifndef PROJECT_HUMANB_HPP
#define PROJECT_HUMANB_HPP

#include <string>
#include "Weapon.hpp"

namespace zob {

	class HumanB {
	private:
		std::string name;
		zob::Weapon *weapon;
	public:
		HumanB(const std::string &name);

		void setWeapon(Weapon &weapon);
		void attack() const;
	};
}

#endif //PROJECT_HUMANB_HPP
