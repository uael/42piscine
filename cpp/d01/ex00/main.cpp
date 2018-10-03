#include "Pony.hpp"

static void ponyOnTheStack() {
	std::cout << "Master - Wakeup stack pony !\n";

	zob::Pony pony = zob::Pony();
	pony.run();

	std::cout << "Master - You are so ugly, bye stack pony..\n";
}

static void ponyOnTheHeap() {
	std::cout << "Master - Wakeup heap pony !\n";

	zob::Pony *pony = new zob::Pony();
	pony->run();

	std::cout << "Master - You are so ugly, bye heap pony..\n";
	delete pony;
}

int main() {
	ponyOnTheStack();
	ponyOnTheHeap();
	return 0;
}
