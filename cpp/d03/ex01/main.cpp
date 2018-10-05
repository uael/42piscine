#include <iostream>

#include "ScavTrap.hpp"

int main() {

	zob::ScavTrap st1("Derick");
	zob::ScavTrap st2("Rick");
	zob::ScavTrap st3(st1);
	std::cout << std::endl;


	std::cout << st1 << std::endl;
	std::cout << st2 << std::endl;
	std::cout << st3 << std::endl;
	std::cout << std::endl;

	st3 = st2;
	std::cout << st1 << std::endl;
	std::cout << st2 << std::endl;
	std::cout << st3 << std::endl;
	std::cout << std::endl;

	st1.rangedAttack("Bob");
	std::cout << st1 << std::endl;
	std::cout << st2 << std::endl;
	std::cout << std::endl;

	st1.meleeAttack("Bob");
	std::cout << st1 << std::endl;
	std::cout << st2 << std::endl;
	std::cout << std::endl;

	st1.takeDamage(3);
	std::cout << st1 << std::endl;
	std::cout << st2 << std::endl;
	std::cout << std::endl;

	st1.beRepaired(3);
	std::cout << st1 << std::endl;
	std::cout << st2 << std::endl;
	std::cout << std::endl;

	st1.takeDamage(1000);
	std::cout << st1 << std::endl;
	std::cout << st2 << std::endl;
	std::cout << std::endl;

	st1.beRepaired(1000);
	std::cout << st1 << std::endl;
	std::cout << st2 << std::endl;
	std::cout << std::endl;

	st1.challengeNewcomer();
	std::cout << st1 << std::endl;
	st1.challengeNewcomer();
	std::cout << st1 << std::endl;
	st1.challengeNewcomer();
	std::cout << st1 << std::endl;
	st1.challengeNewcomer();
	std::cout << st1 << std::endl;
	st1.challengeNewcomer();
	std::cout << st1 << std::endl;
	std::cout << std::endl;

	return 0;
}