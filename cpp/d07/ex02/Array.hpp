#ifndef PROJECT_ARRAY_HPP
#define PROJECT_ARRAY_HPP

#include <stdexcept>

namespace zob {

	template <typename T>
	class Array {
	private:
		T *data;
		unsigned len;

	public:
		Array(unsigned n = 0) : data(new T[n]), len(n) { }
		Array(const Array &src) { *this = src; };

		virtual ~Array() { delete[] data; }

		Array &operator=(const Array &src) {
			delete[] data;
			data = new T[src.len];
			len = src.len;
			for (unsigned i = 0; i < len; ++i) data[i] = src.data[i];
			return *this;
		}

		unsigned size() const { return len; }

		T &operator[](unsigned int i) const throw(std::runtime_error) {
			if (i < 0 || i >= len) throw std::runtime_error("out of bounds");
			return data[i];
		}
	};
}

#endif //PROJECT_ARRAY_HPP
