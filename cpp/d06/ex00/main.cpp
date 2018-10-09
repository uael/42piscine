#include <iostream>
#include <string>

#include "Value.hpp"

int main(int ac, char *av[]) {
	if (ac != 2) {
		std::cerr << "this program only take one argument" << std::endl;
		return 1;
	}

	zob::Value val(*(av + 1));

	std::cout.precision(1);
	std::cout << std::fixed;

	std::cout << "char: "; val.dump_char(); std::cout << std::endl;
	std::cout << "int: "; val.dump_int(); std::cout << std::endl;
	std::cout << "float: "; val.dump_float(); std::cout << std::endl;
	std::cout << "double: "; val.dump_double(); std::cout << std::endl;

	return 0;
}
