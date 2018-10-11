#include <iostream>
#include "Array.hpp"

int main() {
	zob::Array<int> a(10);

	std::cout << "a size: " << a.size() << std::endl;
	for (unsigned i = 0; i < a.size(); ++i) a[i] = a.size() - i;
	for (unsigned i = 0; i < a.size(); ++i)
		std::cout << "a[" << i << "] = " << a[i] << std::endl;

	zob::Array<int> b;

	std::cout << "b size: " << b.size() << std::endl;

	return 0;
}
