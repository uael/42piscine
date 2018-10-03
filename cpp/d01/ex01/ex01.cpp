#include <iostream>

void memoryLeak(void) {
	std::string	*panthere = new std::string("String panthere");
	std::cout << *panthere << std::endl;
	delete panthere;
}

int main() {
	memoryLeak();
	return 0;
}
