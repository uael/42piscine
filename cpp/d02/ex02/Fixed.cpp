#include "Fixed.hpp"

const int zob::Fixed::fbits = 8;

zob::Fixed::Fixed() : value(0) { }

zob::Fixed::Fixed(int const value) {
	setRawBits(value);
}

zob::Fixed::Fixed(float const value) {
	setRawBits(value);
}

zob::Fixed::Fixed(const zob::Fixed &other) : value(other.value) { }

zob::Fixed::~Fixed() { }

zob::Fixed &zob::Fixed::operator=(zob::Fixed other) {
	Fixed::value = other.value;
	return *this;
}

zob::Fixed &zob::Fixed::operator=(int value) {
	setRawBits(value);
	return *this;
}

zob::Fixed &zob::Fixed::operator=(float value) {
	setRawBits(value);
	return *this;
}

int zob::Fixed::getRawBits() const {
	return value;
}

void zob::Fixed::setRawBits(int const value) {
	Fixed::value = static_cast<int>(static_cast<float>(value << Fixed::fbits));
}

void zob::Fixed::setRawBits(float const value) {
	Fixed::value = static_cast<int>(value * (1 << Fixed::fbits));
}

int zob::Fixed::toInt() const {
	return value / (1 << Fixed::fbits);
}

float zob::Fixed::toFloat() const {
	return static_cast<float>(value) / static_cast<float>(1 << Fixed::fbits);
}

bool zob::Fixed::operator==(const zob::Fixed &rhs) const {
	return value == rhs.value;
}

bool zob::Fixed::operator!=(const zob::Fixed &rhs) const {
	return !(rhs == *this);
}

bool zob::Fixed::operator<(const zob::Fixed &rhs) const {
	return value < rhs.value;
}

bool zob::Fixed::operator>(const zob::Fixed &rhs) const {
	return rhs < *this;
}

bool zob::Fixed::operator<=(const zob::Fixed &rhs) const {
	return !(rhs < *this);
}

bool zob::Fixed::operator>=(const zob::Fixed &rhs) const {
	return !(*this < rhs);
}

zob::Fixed zob::Fixed::operator+(const zob::Fixed &rhs) const {
	zob::Fixed r;

	r.value = value + rhs.value;
	return r;
}

zob::Fixed zob::Fixed::operator-(const zob::Fixed &rhs) const {
	zob::Fixed r;

	r.value = value - rhs.value;
	return r;
}

zob::Fixed zob::Fixed::operator*(const zob::Fixed &rhs) const {
	zob::Fixed r;

	r.setRawBits(toFloat() * rhs.toFloat());
	return r;
}

zob::Fixed zob::Fixed::operator/(const zob::Fixed &rhs) const {
	zob::Fixed r;

	r.setRawBits(toFloat() / rhs.toFloat());
	return r;
}

zob::Fixed &zob::Fixed::operator++() {
	++value;
	return *this;
}

const zob::Fixed zob::Fixed::operator++(int) {
	zob::Fixed r(*this);

	++(*this);
	return r;
}

zob::Fixed &zob::Fixed::operator--() {
	--value;
	return *this;
}

const zob::Fixed zob::Fixed::operator--(int) {
	zob::Fixed r(*this);

	--(*this);
	return r;
}

zob::Fixed &zob::Fixed::min(zob::Fixed &lhs, zob::Fixed &rhs) {
	return lhs < rhs ? lhs : rhs;
}

const zob::Fixed &zob::Fixed::min(const zob::Fixed &lhs, const zob::Fixed &rhs) {
	return lhs < rhs ? lhs : rhs;
}

zob::Fixed &zob::Fixed::max(zob::Fixed &lhs, zob::Fixed &rhs) {
	return lhs > rhs ? lhs : rhs;
}

const zob::Fixed &zob::Fixed::max(const zob::Fixed &lhs, const zob::Fixed &rhs) {
	return lhs > rhs ? lhs : rhs;
}

std::ostream &operator<<(std::ostream &os, const zob::Fixed &fixed) {
	return os << fixed.toFloat();
}
