#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int					_fixedPointValue;
	static const int	_fractionalBits = 8;

public:

	Fixed(void);
	
	// constructeur entier
	Fixed(const int value);
	
	// constructeur float
	Fixed(const float value);
	
	//recopie
	Fixed(const Fixed& other);
	
	// modif
	Fixed& operator=(const Fixed& other);
	
	~Fixed(void);
	
	// valeur
	int getRawBits(void) const;
	void setRawBits(int const raw);
	
	// Nouvelles fonctions de conversion
	float toFloat(void) const;
	int toInt(void) const;

};

// surcharge
std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif
