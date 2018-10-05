#ifndef PROJECT_SCAVTRAP_HPP
#define PROJECT_SCAVTRAP_HPP

#include <string>
#include <ostream>
#include "ClapTrap.hpp"

namespace zob {

	class ScavTrap : public ClapTrap {
	public:
		ScavTrap(const std::string &name);

		ScavTrap(const ScavTrap &other);

		virtual ~ScavTrap();

		ScavTrap &operator=(ScavTrap other);

		void challengeNewcomer();
	};
}

#endif //PROJECT_SCAVTRAP_HPP
