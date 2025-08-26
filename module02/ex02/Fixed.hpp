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
	
	// Opérateurs de comparaison
	bool operator>(const Fixed& other) const;
	bool operator<(const Fixed& other) const;
	bool operator>=(const Fixed& other) const;
	bool operator<=(const Fixed& other) const;
	bool operator==(const Fixed& other) const;
	bool operator!=(const Fixed& other) const;
	
	// Opérateurs arithmétiques
	Fixed operator+(const Fixed& other) const;
	Fixed operator-(const Fixed& other) const;
	Fixed operator*(const Fixed& other) const;
	Fixed operator/(const Fixed& other) const;
	
	// Opérateurs d'incrémentation et décrémentation
	Fixed& operator++(void);		// pré-incrémentation
	Fixed operator++(int);			// post-incrémentation
	Fixed& operator--(void);		// pré-décrémentation
	Fixed operator--(int);			// post-décrémentation
	
	// Fonctions statiques min et max
	static Fixed& min(Fixed& a, Fixed& b);
	static const Fixed& min(const Fixed& a, const Fixed& b);
	static Fixed& max(Fixed& a, Fixed& b);
	static const Fixed& max(const Fixed& a, const Fixed& b);

};

// Surcharge de l'opérateur d'insertion
std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif
