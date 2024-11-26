#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->val = 0;
}

Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called" << std::endl;
	this->val = num << this->FractionalBits;
}

Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called" << std::endl;
	this->val = roundf(num * (1 << this->FractionalBits));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if(this != &fixed)
	{
		this->val = fixed.getRawBits();
	}
	return *this;
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