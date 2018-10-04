#include <iostream>
#include "Fixed.hpp"

int main() {
	zob::Fixed a;
	zob::Fixed const b(zob::Fixed(5.05f) * zob::Fixed(2));
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << zob::Fixed::max(a, b) << std::endl;
	return 0;
}