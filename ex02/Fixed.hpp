#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <fstream>
#include <cmath>

class Fixed
{
	public:
		Fixed();
		Fixed(const int num);
		Fixed(const float num);
		~Fixed();
		Fixed(const Fixed &fixed);
		Fixed &operator=(const Fixed &fixed);

		//비교연산자
		bool operator==(Fixed const &fixed) const;
		bool operator!=(Fixed const &fixed) const;
		bool operator>(Fixed const &fixed) const;
		bool operator<(Fixed const &fixed) const;
		bool operator>=(Fixed const &fixed) const;
		bool operator<=(Fixed const &fixed) const;

		//증감연산자
		Fixed &operator++();
		Fixed operator++(int);
		Fixed &operator--();
		Fixed operator--(int);

		//산술연산자
		Fixed operator+(Fixed const &fixed);
		Fixed operator-(Fixed const &fixed);
		Fixed operator*(Fixed const &fixed);
		Fixed operator/(Fixed const &fixed);

		//max min
		static Fixed	&max(Fixed &ref1, Fixed &ref2);
		static const Fixed	&max(Fixed const &ref1, Fixed const &ref2);
		static Fixed	&min(Fixed &ref1, Fixed &ref2);
		static const Fixed	&min(Fixed const &ref1, Fixed const &ref2);

		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat( void ) const;
		int toInt( void ) const;
	private:
		int val;
		static const int FractionalBits = 8;
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif