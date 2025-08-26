#include <iostream>
#include "Fixed.hpp"

int main(void) 
{
	std::cout << "=== Test des opérateurs de comparaison ===" << std::endl;
	Fixed a(10);
	Fixed b(5);
	Fixed c(10);
	
	std::cout << "a = " << a << ", b = " << b << ", c = " << c << std::endl;
	std::cout << "a > b: " << (a > b) << std::endl;
	std::cout << "a < b: " << (a < b) << std::endl;
	std::cout << "a >= c: " << (a >= c) << std::endl;
	std::cout << "a <= c: " << (a <= c) << std::endl;
	std::cout << "a == c: " << (a == c) << std::endl;
	std::cout << "a != b: " << (a != b) << std::endl;
	
	std::cout << "\n=== Test des opérateurs arithmétiques ===" << std::endl;
	Fixed x(10.5f);
	Fixed y(3.2f);
	
	std::cout << "x = " << x << ", y = " << y << std::endl;
	std::cout << "x + y = " << (x + y) << std::endl;
	std::cout << "x - y = " << (x - y) << std::endl;
	std::cout << "x * y = " << (x * y) << std::endl;
	std::cout << "x / y = " << (x / y) << std::endl;
	
	std::cout << "\n=== Test des opérateurs d'incrémentation/décrémentation ===" << std::endl;
	Fixed z(42.42f);
	std::cout << "z = " << z << std::endl;
	std::cout << "++z = " << ++z << std::endl;
	std::cout << "z = " << z << std::endl;
	std::cout << "z++ = " << z++ << std::endl;
	std::cout << "z = " << z << std::endl;
	std::cout << "--z = " << --z << std::endl;
	std::cout << "z = " << z << std::endl;
	std::cout << "z-- = " << z-- << std::endl;
	std::cout << "z = " << z << std::endl;
	
	std::cout << "\n=== Test des fonctions min/max ===" << std::endl;
	Fixed m(10);
	Fixed n(20);
	std::cout << "m = " << m << ", n = " << n << std::endl;
	std::cout << "min(m, n) = " << Fixed::min(m, n) << std::endl;
	std::cout << "max(m, n) = " << Fixed::max(m, n) << std::endl;
	
	const Fixed p(5);
	const Fixed q(15);
	std::cout << "p = " << p << ", q = " << q << std::endl;
	std::cout << "min(p, q) = " << Fixed::min(p, q) << std::endl;
	std::cout << "max(p, q) = " << Fixed::max(p, q) << std::endl;
	
	std::cout << "\n=== Test du sujet original ===" << std::endl;
	Fixed r;
	Fixed const s(Fixed(5.05f) * Fixed(2));

	std::cout << r << std::endl;
	std::cout << ++r << std::endl;
	std::cout << r << std::endl;
	std::cout << r++ << std::endl;
	std::cout << r << std::endl;

	std::cout << s << std::endl;

	std::cout << Fixed::max(r, s) << std::endl;

	return 0;
}
