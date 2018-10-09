#include <cstdlib>
#include <stdexcept>
#include <iostream>
#include "Value.hpp"

static zob::Value::Type get_type(const std::string &s) {
	unsigned char nf = 0, np = 0, nm = 0;
	char const *p = s.c_str();

	if (s.size() == 1)
		return isdigit(*p) ? zob::Value::Int : zob::Value::Char;

	if (s == "-inf" || s == "-inff") return zob::Value::NInf;
	if (s == "+inf" || s == "+inff") return zob::Value::Inf;
	if (s == "nan" || s == "nanf") return zob::Value::Nan;

	for (; *p; ++p)
		if (*p == '.') np++;
		else if (*p == 'f') nf++;
		else if (*p == '-') nm++;
		else if (!isdigit(*p)) return zob::Value::None;
	if (nf > 1 || np > 1 || nm > 1 || (nf && !np))
		return zob::Value::None;
	if (np && nf)
		return zob::Value::Float;
	else if (np)
		return zob::Value::Double;
	return zob::Value::Int;
}

zob::Value::Value(const char *s) : val(0) {
	switch (type = get_type(s)) {
		case Char:
			val = static_cast<long double>(s[0]);
			break;
		case Int:
			val = static_cast<long double>(atoi(s));
			break;
		case Float:
			val = static_cast<long double>(strtof(s, NULL));
			break;
		case Double:
			val = atof(s);
			break;
		default: break;
	}
}

zob::Value::Value(const zob::Value &src) { *this = src; }

zob::Value::~Value() { }

zob::Value &zob::Value::operator=(const zob::Value &src) {
	val = src.val;
	type = src.type;
	return *this;
}

void zob::Value::dump_char() const {
	if (type >= Inf)
		std::cout << "impossible";
	else if (val > 126 || val < 32)
		std::cout << "Non displayable";
	else
		std::cout << "'" << static_cast<char>(val) << "'";
}

void zob::Value::dump_int() const {
	if (type >= Inf)
		std::cout << "impossible";
	else
		std::cout << static_cast<int>(val);
}

void zob::Value::dump_float() const {
	switch (type) {
		case Inf: std::cout << "+inff"; break;
		case NInf: std::cout << "-inff"; break;
		case Nan: std::cout << "nanf"; break;
		default:
			std::cout << val << "f";
			break;
	}
}

void zob::Value::dump_double() const {
	switch (type) {
		case Inf: std::cout << "+inf"; break;
		case NInf: std::cout << "-inf"; break;
		case Nan: std::cout << "nan"; break;
		default:
			std::cout << val;
			break;
	}
}
