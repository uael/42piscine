#include <iostream>
#include <cstring>

template <typename T>
void swap(T &a, T &b) {
	T c = a;

	a = b;
	b = c;
}

template <typename T>
T min(T a, T b) {
	return a < b ? a : b;
}

template <typename T>
T max(T a, T b) {
	return a > b ? a : b;
}

class Zob {
public:
	Zob(int n) : v(n) { }
	bool operator>(Zob &test) { return v > test.v; }
	bool operator<(Zob &test) { return v < test.v; }
	int v;

	friend std::ostream &operator<<(std::ostream &os, const Zob &zob) {
		os << zob.v;
		return os;
	}
};

int main() {
	{
		int a = 42, b = 21;

		std::cout << "a: " << a << ", b: " << b << std::endl;
		swap(a, b);
		std::cout << "a: " << a << ", b: " << b << std::endl;
		std::cout << "min: " << min(a, b) << ", max: " << max(a, b) << std::endl;
	}
	{
		Zob a(42), b(21);

		std::cout << "a: " << a << ", b: " << b << std::endl;
		swap(a, b);
		std::cout << "a: " << a << ", b: " << b << std::endl;
		std::cout << "min: " << min(a, b) << ", max: " << max(a, b) << std::endl;
	}
}
