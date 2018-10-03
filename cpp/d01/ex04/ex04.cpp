#include <iostream>

int main() {
	std::string str = "HI THIS IS BRAIN", *ptr = &str, &ref = str;

	std::cout << *ptr << std::endl << ref << std::endl;
	return 0;
}