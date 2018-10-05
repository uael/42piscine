#ifndef PROJECT_NINJATRAP_HPP
#define PROJECT_NINJATRAP_HPP

#include <string>
#include <ostream>

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

namespace zob {

	class NinjaTrap : public ClapTrap {
	public:
		NinjaTrap(const std::string &name);

		NinjaTrap(const NinjaTrap &other);

		virtual ~NinjaTrap();

		NinjaTrap &operator=(NinjaTrap other);

		void ninjaShoebox(zob::FragTrap const &target);

		void ninjaShoebox(zob::ScavTrap const &target);

		void ninjaShoebox(zob::NinjaTrap const &target);
	};
}

#endif //PROJECT_NINJATRAP_HPP
