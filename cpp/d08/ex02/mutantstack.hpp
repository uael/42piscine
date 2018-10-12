#ifndef PROJECT_MUTANTSTACK_HPP
#define PROJECT_MUTANTSTACK_HPP

#include <stack>

namespace zob {

	template <typename T, typename S = std::deque<T> >
	class MutantStack : public std::stack<T, S> {
	public:
		typedef typename S::iterator iterator;

		iterator begin() { return this->c.begin(); }
		iterator end() { return this->c.end(); }
	};
}

#endif //PROJECT_MUTANTSTACK_HPP
