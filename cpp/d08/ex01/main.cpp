

#include <iostream>
#include <cstdlib>

#include "span.hpp"

int main() {
	{
		zob::Span sp = zob::Span(5);

		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		try { sp.addNumber(11); }
		catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	{
		try { zob::Span sp = zob::Span(0); }
		catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
		try { zob::Span sp = zob::Span(1); }
		catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	{
		const unsigned size = 10000;
		zob::Span sp = zob::Span(size);
		srand(time(NULL));

		for (unsigned i = 0; i < size; ++i)
			sp.addNumber(rand() % size);

		std::cout << sp << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	return 0;
}
