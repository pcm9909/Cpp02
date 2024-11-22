#ifndef FIXED_HPP
#define FIXED_HPP

//FixedPointBits = 전체 비트수
//FractionalBits = 소수부 비트수

class Fixed
{
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed &fixed);
		Fixed &operator=(const Fixed &fixed);
		int getRawBits(void) const;
		void setRawBits(int const raw);
	private:
		int FixedPointBits;
		static const int FractionalBits = 8;
};

#endif