#include <iostream>

#include "Human.hpp"

int main() {
	zob::Human bob;
	std::cout << bob.identify() << std::endl;
	std::cout << bob.getBrain().identify() << std::endl;
}