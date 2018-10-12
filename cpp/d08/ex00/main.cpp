

#include <iostream>
#include <vector>
#include <list>

#include "easyfind.hpp"

int main() {
	int a[] = { 1, 2, 3, 4, 5 };

	std::list<int> list(a, a + 5);
	std::cout << easyfind(list, 2) << std::endl;
	std::cout << easyfind(list, 1) << std::endl;
	std::cout << easyfind(list, 0) << std::endl ;

	std::vector<int> vector(a, a + 5);
	std::cout << easyfind(vector, 2) << std::endl;
	std::cout << easyfind(vector, 1) << std::endl;
	std::cout << easyfind(vector, 0) << std::endl;

	return 0;
}
