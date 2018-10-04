#ifndef PROJECT_FIXED_HPP
#define PROJECT_FIXED_HPP

#include <ostream>

namespace zob {

	class Fixed {
	private:
		static const int fbits;
		int value;
	public:
		Fixed();
		Fixed(int value);
		Fixed(float value);
		Fixed(const Fixed &other);
		virtual ~Fixed();

		Fixed& operator=(Fixed other);
		Fixed& operator=(int value);
		Fixed& operator=(float value);

		int getRawBits() const;
		void setRawBits(int value);
		void setRawBits(float value);

		int toInt() const;
		float toFloat() const;

		bool operator==(const Fixed &rhs) const;
		bool operator!=(const Fixed &rhs) const;
		bool operator<(const Fixed &rhs) const;
		bool operator>(const Fixed &rhs) const;
		bool operator<=(const Fixed &rhs) const;
		bool operator>=(const Fixed &rhs) const;

		Fixed operator+(const Fixed &rhs) const;
		Fixed operator-(const Fixed &rhs) const;
		Fixed operator*(const Fixed &rhs) const;
		Fixed operator/(const Fixed &rhs) const;

		Fixed& operator++();
		const Fixed operator++(int);
		Fixed& operator--();
		const Fixed operator--(int);

		static Fixed &min(Fixed &lhs, Fixed &rhs);
		static const Fixed &min(const Fixed &lhs, const Fixed &rhs);
		static Fixed &max(Fixed &lhs, Fixed &rhs);
		static const Fixed &max(const Fixed &lhs, const Fixed &rhs);
	};
}

std::ostream &operator<<(std::ostream &os, const zob::Fixed &fixed);

#endif //PROJECT_FIXED_HPP
