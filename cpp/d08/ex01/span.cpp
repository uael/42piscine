#include <stdexcept>
#include <algorithm>
#include "span.hpp"

zob::Span::Span(unsigned size)
	: ints() {
	if (size <= 1)
		throw std::runtime_error("another try, you idiot");
	ints.reserve(size);
}

zob::Span::Span(const zob::Span &src) {
	*this = src;
}

zob::Span::~Span() { }

zob::Span &zob::Span::operator=(const zob::Span &src) {
	ints = src.ints;
	return *this;
}

/**
 * Insert sorted here to make lookup time for shortest and largest span
 * more efficient
 * @param n value to add
 */
void zob::Span::addNumber(int n) throw(std::runtime_error) {
	if (ints.size() == ints.capacity())
		throw std::runtime_error("out of bounds");
	ints.insert(std::upper_bound(ints.begin(), ints.end(), n), n);
}

unsigned zob::Span::shortestSpan() const {
	std::vector<int>::const_iterator it;
	unsigned span = 0xffff;

	for(it = ints.begin(); it + 1 != ints.end(); ++it) {
		unsigned s = static_cast<unsigned>(*(it + 1) - *it);

		if (s < span) span = s;
		if (s == 0) break;
	}

	return span;
}

unsigned zob::Span::longestSpan() const {
	return static_cast<unsigned>(ints.back() - ints.front());
}

namespace zob {
	std::ostream &operator<<(std::ostream &os, const zob::Span &span) {
		std::vector<int>::const_iterator it;

		os << '{';
		for(it = span.ints.begin(); it != span.ints.end(); ++it)
			os << *it << ',';
		os << '}';

		return os;
	}
}
