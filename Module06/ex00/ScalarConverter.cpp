#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
	(void)src;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs)
{
	(void)rhs;
	return (*this);
}

ScalarConverter::~ScalarConverter(void)
{
}

static bool isInf(const std::string &str)
{
	return (str == "+inf" || str == "-inf" || str == "inf" ||
			str == "+inff" || str == "-inff" || str == "inff");
}

static bool isNan(const std::string &str)
{
	return (str == "nan" || str == "nanf");
}

static bool isPseudoLiteral(const std::string &str)
{
	return (isInf(str) || isNan(str));
}

