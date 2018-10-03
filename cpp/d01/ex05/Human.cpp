#include "Human.hpp"

zob::Human::Human() { }

std::string zob::Human::identify() {
	return brain.identify();
}

const zob::Brain &zob::Human::getBrain() const {
	return brain;
}
