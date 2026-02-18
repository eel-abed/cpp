#include "Fixed.hpp"

Fixed::Fixed(void) : _fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

//entier
Fixed::Fixed(const int value) : _fixedPointValue(value << _fractionalBits)
{
	std::cout << "Int constructor called" << std::endl;
}

// float
Fixed::Fixed(const float value) : _fixedPointValue(roundf(value * (1 << _fractionalBits)))
{
	std::cout << "Float constructor called" << std::endl;
}

// recopie
Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

//modif
Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_fixedPointValue = other.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

// get value
int Fixed::getRawBits(void) const
{
	return (this->_fixedPointValue);
}

// set value
void Fixed::setRawBits(int const raw)
{
	this->_fixedPointValue = raw;
}

// Conversion en float
float Fixed::toFloat(void) const
{
	return static_cast<float>(this->_fixedPointValue) / (1 << _fractionalBits);
}

// Conversion en int
int Fixed::toInt(void) const
{
	return this->_fixedPointValue >> _fractionalBits;
}

// operatieur conparaison
bool Fixed::operator>(const Fixed& other) const
{
	return this->_fixedPointValue > other._fixedPointValue;
}

bool Fixed::operator<(const Fixed& other) const
{
	return this->_fixedPointValue < other._fixedPointValue;
}

bool Fixed::operator>=(const Fixed& other) const
{
	return this->_fixedPointValue >= other._fixedPointValue;
}

bool Fixed::operator<=(const Fixed& other) const
{
	return this->_fixedPointValue <= other._fixedPointValue;
}

bool Fixed::operator==(const Fixed& other) const
{
	return this->_fixedPointValue == other._fixedPointValue;
}

bool Fixed::operator!=(const Fixed& other) const
{
	return this->_fixedPointValue != other._fixedPointValue;
}

// operateur math
Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed result;
	result._fixedPointValue = this->_fixedPointValue + other._fixedPointValue;
	return result;
}

Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed result;
	result._fixedPointValue = this->_fixedPointValue - other._fixedPointValue;
	return result;
}

Fixed Fixed::operator*(const Fixed& other) const
{
	Fixed result;
	result._fixedPointValue = (this->_fixedPointValue * other._fixedPointValue) >> _fractionalBits;
	return result;
}

Fixed Fixed::operator/(const Fixed& other) const
{
	Fixed result;
	result._fixedPointValue = (this->_fixedPointValue << _fractionalBits) / other._fixedPointValue;
	return result;
}

// ++ --
Fixed& Fixed::operator++(void)
{
	this->_fixedPointValue++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	this->_fixedPointValue++;
	return temp;
}

Fixed& Fixed::operator--(void)
{
	this->_fixedPointValue--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	this->_fixedPointValue--;
	return temp;
}

// max/min
Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a > b) ? a : b;
}

// surcharge
std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return out;
}
