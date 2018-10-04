#ifndef PROJECT_FIXED_HPP
#define PROJECT_FIXED_HPP

namespace zob {

	class Fixed {
	private:
		static const int fbits;
		int value;
	public:
		explicit Fixed();
		Fixed(const Fixed &other);
		virtual ~Fixed();

		Fixed& operator=(Fixed other);

		int getRawBits() const;
		void setRawBits(int value);
	};
}

#endif //PROJECT_FIXED_HPP
