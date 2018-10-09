#include <iostream>
#include <cstdlib>

class Base {
public:
	virtual ~Base() { }
};

class A : public Base { };
class B : public Base { };
class C : public Base { };

static Base *generate() {
	int i = rand() % 3;
	if (i == 0) return new A();
	if (i == 1) return new B();
	return new C();
}

static void identify_from_pointer(Base *p) {
	if (dynamic_cast<A *>(p)) std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p)) std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p)) std::cout << "C" << std::endl;
}

static void identify_from_reference(Base &p) {
	if (dynamic_cast<A *>(&p)) std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(&p)) std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(&p)) std::cout << "C" << std::endl;
}

int main() {
	srand(static_cast<unsigned int>(time(NULL)));
	Base *b;

	for (char c = 0; c < 8; ++c) {
		b = generate();
		std::cout << "from pointer:   "; identify_from_pointer(b);
		std::cout << "from reference: "; identify_from_reference(*b);
		delete b;
	}

	return 0;
}
