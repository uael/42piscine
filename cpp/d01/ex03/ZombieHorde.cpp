#include "ZombieHorde.hpp"

zob::ZombieHorde::ZombieHorde(int n) : count(n) {
	buddys = new Zombie[n];

}

void zob::ZombieHorde::announce() const {
	for (int i = 0; i < count; ++i)
		buddys[i].announce();
}

zob::ZombieHorde::~ZombieHorde() {
	delete[] buddys;
}
