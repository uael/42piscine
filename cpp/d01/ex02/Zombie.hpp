#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>

namespace zob {

	class Zombie {
	private:
		std::string name, type;
	public:
		Zombie(const std::string &name, const std::string &type);
		virtual ~Zombie();

		void announce() const;
	};
}

#endif /* !ZOMBIE_HPP */
