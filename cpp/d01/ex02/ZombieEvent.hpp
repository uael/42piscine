#ifndef ZOMBIE_EVENT_HPP
# define ZOMBIE_EVENT_HPP

#include "Zombie.hpp"

namespace zob {

	class ZombieEvent {
	private:
		std::string type;
	public:
		ZombieEvent(const std::string &type);

		virtual ~ZombieEvent();

		void setZombieType(const std::string &type);

		Zombie *newZombie(std::string const &name) const;
	};
}

#endif /* !ZOMBIE_EVENT_HPP */
