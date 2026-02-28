#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange
{
private:
	std::map<std::string, double> _database;

	bool isValidDate(const std::string &date) const;
	bool isValidValue(double value) const;
	double parseValue(const std::string &valueStr) const;
	bool parseLine(const std::string &line, std::string &date, double &value) const;
	double findExchangeRate(const std::string &date) const;

public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);
	~BitcoinExchange();

	void loadDatabase(const std::string &filename);
	void processInputFile(const std::string &filename);
};

#endif
