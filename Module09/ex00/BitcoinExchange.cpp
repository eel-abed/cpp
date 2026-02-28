#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <stdexcept>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _database(other._database) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		_database = other._database;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

static std::string trim(const std::string &str)
{
	size_t start = 0;
	size_t end = str.length();

	while (start < end && (str[start] == ' ' || str[start] == '\t'))
		start++;
	while (end > start && (str[end - 1] == ' ' || str[end - 1] == '\t'))
		end--;

	return str.substr(start, end - start);
}

bool BitcoinExchange::isValidDate(const std::string &date) const
{
	if (date.length() != 10)
		return false;
	if (date[4] != '-' || date[7] != '-')
		return false;

	for (size_t i = 0; i < date.length(); i++)
	{
		if (i != 4 && i != 7)
		{
			if (!isdigit(date[i]))
				return false;
		}
	}

	int year = atoi(date.substr(0, 4).c_str());
	int month = atoi(date.substr(5, 2).c_str());
	int day = atoi(date.substr(8, 2).c_str());

	if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
		return false;

	int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (year == 2012 || year == 2016 || year == 2020)
		daysInMonth[2] = 29;

	if (day > daysInMonth[month])
		return false;

	return true;
}

bool BitcoinExchange::isValidValue(double value) const
{
	return value >= 0 && value <= 1000;
}

double BitcoinExchange::parseValue(const std::string &valueStr) const
{
	char *endptr;
	double value = strtod(valueStr.c_str(), &endptr);

	if (*endptr != '\0' && *endptr != '\n' && *endptr != ' ' && *endptr != '\t')
		throw std::invalid_argument("invalid value format");

	return value;
}

bool BitcoinExchange::parseLine(const std::string &line, std::string &date, double &value) const
{
	size_t pipePos = line.find('|');

	if (pipePos == std::string::npos)
		return false;

	date = trim(line.substr(0, pipePos));
	std::string valueStr = trim(line.substr(pipePos + 1));

	if (date.empty() || valueStr.empty())
		return false;

	try
	{
		value = parseValue(valueStr);
	}
	catch (const std::exception &e)
	{
		return false;
	}

	return true;
}

double BitcoinExchange::findExchangeRate(const std::string &date) const
{
	std::map<std::string, double>::const_iterator it = _database.lower_bound(date); //lowerbound c pour l'element le plus proche

	if (it != _database.end() && it->first == date)
		return it->second;

	// same shit mais si on va plus haut
	if (it == _database.begin())
		throw std::runtime_error("no exchange rate available for this date");

	--it;
	return it->second;
}


void BitcoinExchange::loadDatabase(const std::string &filename)
{
	std::ifstream file(filename.c_str());

	if (!file.is_open())
		throw std::runtime_error("Error: could not open database file.");

	std::string line;
	bool firstLine = true;

	while (std::getline(file, line))
	{
		if (firstLine)
		{
			firstLine = false;
			continue;
		}

		size_t commaPos = line.find(',');
		if (commaPos == std::string::npos)
			continue;

		std::string date = trim(line.substr(0, commaPos));
		std::string rateStr = trim(line.substr(commaPos + 1));

		if (!isValidDate(date))
			continue;

		try
		{
			double rate = parseValue(rateStr);
			_database[date] = rate;
		}
		catch (const std::exception &e)
		{
			continue;
		}
	}

	file.close();

	if (_database.empty())
		throw std::runtime_error("Error: database is empty.");
}


void BitcoinExchange::processInputFile(const std::string &filename)
{
	std::ifstream file(filename.c_str());

	if (!file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}

	std::string line;
	bool firstLine = true;

	while (std::getline(file, line))
	{

		if (firstLine)
		{
			firstLine = false;
			continue;
		}


		if (trim(line).empty())
			continue;

		std::string date;
		double value;

		if (!parseLine(line, date, value))
		{
			std::cerr << "Error: bad input => " << trim(line) << std::endl;
			continue;
		}

		if (!isValidDate(date))
		{
			std::cerr << "Error: bad input => " << date << std::endl;
			continue;
		}

		if (value < 0)
		{
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}

		if (value > 1000)
		{
			std::cerr << "Error: too large a number." << std::endl;
			continue;
		}

		try
		{
			double rate = findExchangeRate(date);
			double result = value * rate;
			std::cout << date << " => " << value << " = " << result << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}

	file.close();
}
