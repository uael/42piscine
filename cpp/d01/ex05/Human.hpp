#ifndef HUMAN_HPP
#define HUMAN_HPP

#include "Brain.hpp"

namespace zob {
	class Human {
	private:
		zob::Brain brain;
	public:
		Human();
		std::string identify();

		const Brain &getBrain() const;
	};
}

#endif //HUMAN_HPP
