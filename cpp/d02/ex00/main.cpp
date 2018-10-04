#include <iostream>
#include "Fixed.hpp"

int main() {
	zob::Fixed a;
	zob::Fixed b(a);
	zob::Fixed c;
	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return 0;
}