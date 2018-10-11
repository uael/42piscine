#include <iostream>

template <typename T>
void iter(T a[], unsigned len, void (*fn)(T e)) {
	for (unsigned i = 0; i < len; ++i) fn(a[i]);
}

void print_int(int i) {
	std::cout << i << std::endl;
}

int main() {
	int a[] = { 5, 4, 3, 2, 1 };

	iter(a, 5, print_int);

	return 0;
}
