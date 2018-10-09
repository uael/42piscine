#ifndef PROJECT_VALUE_HPP
#define PROJECT_VALUE_HPP

#include <string>

namespace zob {

	class Value {
	public:
		enum Type {
			None, Char, Int, Float, Double,
			Inf, NInf, Nan
		};

		Value(const char *string);
		Value(const Value &src);
		virtual ~Value();

		Value &operator=(const Value &src);

		void dump_char() const;
		void dump_int() const;
		void dump_float() const;
		void dump_double() const;

	private:
		long double val;
		Type type;
	};
}

#endif //PROJECT_VALUE_HPP
