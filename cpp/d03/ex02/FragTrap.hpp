#ifndef PROJECT_FRAGTRAP_HPP
#define PROJECT_FRAGTRAP_HPP

#include <string>
#include <ostream>
#include "ClapTrap.hpp"

namespace zob {

	class FragTrap : public ClapTrap {
	public:
		FragTrap(const std::string &name);

		FragTrap(const FragTrap &other);

		virtual ~FragTrap();

		FragTrap &operator=(FragTrap other);

		void vaulthunter_dot_exe(std::string const &target);
	};
}

#endif //PROJECT_FRAGTRAP_HPP
