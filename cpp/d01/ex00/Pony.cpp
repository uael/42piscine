#include "Pony.hpp"

zob::Pony::Pony()
{ std::cout << "I'm a beautiful pony !\n"; }

zob::Pony::~Pony()
{ std::cout << "Oh no, i'm dying, arrghhhh!!\n"; }

void zob::Pony::run()
{
	std::cout
		<< "Look at me master, I'm running so smoothly and with "
		   "so much elegance\n";
}
