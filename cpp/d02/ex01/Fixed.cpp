#include <iostream>
#include "Fixed.hpp"

const int zob::Fixed::fbits = 8;

zob::Fixed::Fixed() : value(0) {
	std::cout << "Default constructor called" << std::endl;
}

zob::Fixed::Fixed(int const value) {
	setRawBits(value);
	std::cout << "Int constructor called" << std::endl;
}

zob::Fixed::Fixed(float const value) {
	setRawBits(value);
	std::cout << "Float constructor called" << std::endl;
}

zob::Fixed::Fixed(const zob::Fixed &other) : value(other.value) {
	std::cout << "Copy constructor called" << std::endl;
}

zob::Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

zob::Fixed &zob::Fixed::operator=(zob::Fixed other) {
	std::cout << "Assignation operator called" << std::endl;
	Fixed::value = other.value;
	return *this;
}

zob::Fixed &zob::Fixed::operator=(int value) {
	std::cout << "Assignation operator called" << std::endl;
	setRawBits(value);
	return *this;
}

zob::Fixed &zob::Fixed::operator=(float value) {
	std::cout << "Assignation operator called" << std::endl;
	setRawBits(value);
	return *this;
}

int zob::Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return value;
}

void zob::Fixed::setRawBits(int const value) {
	std::cout << "setRawBits member function called" << std::endl;
	Fixed::value = static_cast<int>(static_cast<float>(value << Fixed::fbits));
}

void zob::Fixed::setRawBits(float const value) {
	std::cout << "setRawBits member function called" << std::endl;
	Fixed::value = static_cast<int>(value * (1 << Fixed::fbits));
}

int zob::Fixed::toInt() const {
	return value / (1 << Fixed::fbits);
}

float zob::Fixed::toFloat() const {
	return static_cast<float>(value) / static_cast<float>(1 << Fixed::fbits);
}

std::ostream &operator<<(std::ostream &os, const zob::Fixed &fixed) {
	return os << fixed.toFloat();
}
