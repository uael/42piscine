#ifndef ZOMBIE_HORDE_HPP
# define ZOMBIE_HORDE_HPP

#include <string>
#include "Zombie.hpp"

namespace zob {

	class ZombieHorde {
	private:
		Zombie *buddys;
		int count;
	public:
		ZombieHorde(int n);

		virtual ~ZombieHorde();

		void announce() const;
	};
}

#endif /* !ZOMBIE_HORDE_HPP */
