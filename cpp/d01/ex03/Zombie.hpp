#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>

namespace zob {

	class Zombie {
	private:
		std::string name, type;
	public:
		explicit Zombie();
		virtual ~Zombie();

		void announce() const;
	};
}

#endif /* !ZOMBIE_HPP */
