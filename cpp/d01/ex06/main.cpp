#include <iostream>

#include "HumanA.hpp"
#include "HumanB.hpp"

int main() {
	{
		zob::Weapon
			club = zob::Weapon("crude spiked club");
		zob::HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		zob::Weapon
			club = zob::Weapon("crude spiked club");
		zob::HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
}
