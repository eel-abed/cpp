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
	
	// Nouveau constructeur prenant un entier constant
	Fixed(const int value);
	
	// Nouveau constructeur prenant un flottant constant
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

// Surcharge de l'opérateur d'insertion
std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif
