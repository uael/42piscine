#ifndef PROJECT_HUMANA_HPP
#define PROJECT_HUMANA_HPP

#include <string>
#include "Weapon.hpp"

namespace zob {

	class HumanA {
	private:
		std::string name;
		zob::Weapon *weapon;
	public:
		HumanA(const std::string &name, zob::Weapon &weapon);

		void attack() const;
	};
}

#endif //PROJECT_HUMANA_HPP
