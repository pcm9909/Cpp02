#include "Fixed.hpp"

Fixed::Fixed() : FixedPointBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	this->FixedPointBits = fixed.getRawBits();
}

Fixed& Fixed::operator=(const Fixed &fixed)
{
	this->FixedPointBits = fixed.getRawBits();
	return *this;
}

void Fixed::setRawBits(int const raw)
{
	this->FixedPointBits = raw;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return FixedPointBits;
}