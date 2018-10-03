#include <sstream>
#include "Brain.hpp"

zob::Brain::Brain() { }

std::string zob::Brain::identify() const {
	std::stringstream	me;
	me << this;
	return me.str();
}
