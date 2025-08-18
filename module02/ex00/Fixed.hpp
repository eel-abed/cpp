#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int					_fixedPointValue;
	static const int	_fractionalBits = 8;

public:
	// Constructeur par défaut
	Fixed(void);
	
	// Constructeur de recopie
	Fixed(const Fixed& other);
	
	// Surcharge de l'opérateur d'affectation
	Fixed& operator=(const Fixed& other);
	
	// Destructeur
	~Fixed(void);
	
	// Fonction membre pour obtenir la valeur brute
	int getRawBits(void) const;
	
	// Fonction membre pour définir la valeur brute
	void setRawBits(int const raw);
};

#endif
