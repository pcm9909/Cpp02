#include "Fixed.hpp"

Fixed::Fixed()
{
	this->val = 0;
}

Fixed::Fixed(const int num)
{
	this->val = num << this->FractionalBits;
}

Fixed::Fixed(const float num)
{
	this->val = roundf(num * (1 << this->FractionalBits));
}

Fixed::~Fixed()
{
	;
}
Fixed::Fixed(const Fixed &fixed)
{
	*this = fixed;
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
	if(this != &fixed)
	{
		this->val = fixed.val;
	}
	return *this;
}

//비교연산자
bool Fixed::operator==(Fixed const &fixed) const
{
	return (this->getRawBits() == fixed.getRawBits());
}
bool Fixed::operator!=(Fixed const &fixed) const
{
	return (this->getRawBits() != fixed.getRawBits());
}
bool Fixed::operator>(Fixed const &fixed) const
{
	return (this->getRawBits() > fixed.getRawBits());
}
bool Fixed::operator<(Fixed const &fixed) const
{
	return (this->getRawBits() < fixed.getRawBits());
}
bool Fixed::operator>=(Fixed const &fixed) const
{
	return (this->getRawBits() >= fixed.getRawBits());
}
bool Fixed::operator<=(Fixed const &fixed) const
{
	return (this->getRawBits() <= fixed.getRawBits());
}

//증감연산자

Fixed &Fixed::operator++()
{
	this->val++;
	return *this;
}
Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	++(*this);
	return temp;
}

Fixed &Fixed::operator--()
{
	this->val--;
	return *this;
}
Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	--(*this);
	return temp;
}

//산술연산자

Fixed Fixed::operator+(Fixed const &fixed)
{
	Fixed temp(this->toFloat() + fixed.toFloat());
	return temp;
}
Fixed Fixed::operator-(Fixed const &fixed)
{
	Fixed temp(this->toFloat() - fixed.toFloat());
	return temp;
}
Fixed Fixed::operator*(Fixed const &fixed)
{
	Fixed temp(this->toFloat() * fixed.toFloat());
	return temp;
}
Fixed Fixed::operator/(Fixed const &fixed)
{
	Fixed temp(this->toFloat() / fixed.toFloat());
	return temp;
}

//max, min
Fixed&	Fixed::max(Fixed &f1, Fixed &f2)
{
	if (f1 >= f2)
		return f1;
	else
		return f2;
}

const Fixed&	Fixed::max(Fixed const &f1, Fixed const &f2)
{
	if (f1 >= f2)
		return f1;
	else
		return f2;
}

Fixed&	Fixed::min(Fixed &f1, Fixed &f2)
{
	if (f1 <= f2)
		return f1;
	else
		return f2;
}

const Fixed&	Fixed::min(Fixed const &f1, Fixed const &f2)
{
	if (f1 <= f2)
		return f1;
	else
		return f2;
}


void Fixed::setRawBits(int const raw)
{
	this->val = raw;
}

int Fixed::getRawBits(void) const
{
	return val;
}

float Fixed::toFloat(void) const
{
	return (float)this->val / (1 << FractionalBits);
}

int Fixed::toInt(void) const
{
	return this->val >> FractionalBits;
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
    os << fixed.toFloat();
    return os;
}