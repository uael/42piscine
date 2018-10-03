#include <iostream>
#include "ZombieEvent.hpp"

zob::ZombieEvent::ZombieEvent(const std::string &type)
	: type(type) {
	std::cout << "ZombieEvent up !" << std::endl;
}

zob::ZombieEvent::~ZombieEvent() {
	std::cout << "ZombieEvent down." << std::endl;
}

void zob::ZombieEvent::setZombieType(const std::string &type) {
	ZombieEvent::type = type;
}

zob::Zombie *zob::ZombieEvent::newZombie(std::string const &name) const {
	return new zob::Zombie(name, type);
}
