

#include <vector>
#include <stdexcept>
#include <ostream>

#ifndef PROJECT_SPAN_HPP
#define PROJECT_SPAN_HPP

namespace zob {

	class Span {
	public:
		Span(unsigned size);
		Span(Span const &src);
		~Span();

		Span &operator=(Span const &src);

		void addNumber(int n) throw(std::runtime_error);
		unsigned shortestSpan() const;
		unsigned longestSpan() const;

		// debug only no -42 for friend..
		friend std::ostream &operator<<(std::ostream &os, const zob::Span &span);

	private:
		std::vector<int> ints;
	};
}

#endif //PROJECT_SPAN_HPP
