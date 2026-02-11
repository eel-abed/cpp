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

void ScalarConverter::convert(const std::string &str)
{
	std::string input = str;
	bool isFloat = false;

	if (isPseudoLiteral(input))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;

		if (isNan(input))
		{
			std::cout << "float: nanf" << std::endl;
			std::cout << "double: nan" << std::endl;
		}
		else if (input == "-inf" || input == "-inff")
		{
			std::cout << "float: -inff" << std::endl;
			std::cout << "double: -inf" << std::endl;
		}
		else
		{
			std::cout << "float: +inff" << std::endl;
			std::cout << "double: +inf" << std::endl;
		}
		return;
	}

	char charValue = '\0';
	bool isCharLiteral = false;


	if (input.length() == 1 && !std::isdigit(input[0]))
	{
		charValue = input[0];
		isCharLiteral = true;
	}

	if (!isCharLiteral && !input.empty() && input[input.length() - 1] == 'f')
	{
		isFloat = true;
		input = input.substr(0, input.length() - 1);
	}

	double doubleValue = 0.0;
	if (!isCharLiteral)
	{
		std::stringstream ss(input);
		ss >> doubleValue;

		if (ss.fail() || !ss.eof())
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
			return;
		}
	}
	else
	{
		doubleValue = static_cast<double>(static_cast<unsigned char>(charValue));
	}

	bool intPossible = (doubleValue >= std::numeric_limits<int>::min() &&
						doubleValue <= std::numeric_limits<int>::max() &&
						doubleValue == std::floor(doubleValue));

	if (isCharLiteral)
	{
		if (charValue < 32 || charValue >= 127)
		{
			std::cout << "char: Non displayable" << std::endl;
		}
		else
		{
			std::cout << "char: '" << charValue << "'" << std::endl;
		}
	}
	else if (doubleValue >= 0 && doubleValue <= 127)
	{
		int charInt = static_cast<int>(doubleValue);
		if (charInt < 32 || charInt >= 127)
		{
			std::cout << "char: Non displayable" << std::endl;
		}
		else
		{
			std::cout << "char: '" << static_cast<char>(charInt) << "'" << std::endl;
		}
	}
	else
	{
		std::cout << "char: impossible" << std::endl;
	}

	if (intPossible)
	{
		std::cout << "int: " << static_cast<int>(doubleValue) << std::endl;
	}
	else
	{
		std::cout << "int: impossible" << std::endl;
	}
	float floatValue = static_cast<float>(doubleValue);
	if (std::isinf(doubleValue) || std::isnan(doubleValue))
	{
		std::cout << "float: " << floatValue << "f" << std::endl;
	}
	else if (floatValue == std::floor(floatValue))
	{
		std::cout << std::fixed << std::setprecision(1) << "float: " << floatValue << "f" << std::endl;
	}
	else
	{
		std::cout << std::fixed << std::setprecision(std::numeric_limits<float>::digits10) << "float: " << floatValue << "f" << std::endl;
	}
	if (std::isinf(doubleValue) || std::isnan(doubleValue))
	{
		std::cout << "double: " << doubleValue << std::endl;
	}
	else if (doubleValue == std::floor(doubleValue))
	{
		std::cout << std::fixed << std::setprecision(1) << "double: " << doubleValue << std::endl;
	}
	else
	{
		std::cout << std::fixed << std::setprecision(std::numeric_limits<double>::digits10) << "double: " << doubleValue << std::endl;
	}
}
