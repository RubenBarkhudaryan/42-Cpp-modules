#include <fstream>
#include <iostream>
#include <stdexcept>
#include <cctype>
#include <cstdlib>
#include <map>
#include <list>
#include <string>
#include <utility>

#include "./BitcoinExchange.hpp"

/*-----BitcoinExchange ctors/dtor-----*/
BitcoinExchange::BitcoinExchange()
{}
BitcoinExchange::BitcoinExchange(const BitcoinExchange&)
{}
BitcoinExchange::~BitcoinExchange()
{}

/*-----BitcoinExchange operators-----*/
BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange&)
{
	return (*this);
}

/*-----BitcoinExchange helpers-----*/
std::string	BitcoinExchange::trimStr(const std::string& input)
{
	std::size_t	start;
	std::size_t	end;

	start = 0;
	end = input.size() - 1;

	if (start == end && !input.empty())
		return (input);

	while (start < input.size())
	{
		if (!isspace(input[start]))
			break;
		++start;
	}
	while (end > start)
	{
		if (!isspace(input[end]))
			break;
		--end;
	}
	if (end >= start)
		return (input.substr(start, (end - start) + 1));
	return ("");
}

std::list<std::string>	BitcoinExchange::split(const std::string& str, char target)
{
	std::size_t					i;
	std::size_t					j;
	std::size_t					size;
	std::list<std::string>	result;

	i = 0;
	size = str.size();
	while (i < size)
	{
		j = 0;
		while (i + j < size && str[i + j] != target)
			++j;
		if (j > 0)
		{
			result.push_back(str.substr(i, j));
			i += j;
		}
		if (i < size && str[i] == target)
			++i;
	}
	return (result);
}

bool	BitcoinExchange::isLeap(int year)
{
	return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

bool	BitcoinExchange::isValidDate(const std::string& date)
{
	std::list<std::string>	split_line;
	static int	days[] = {
		0,31,28,31,30,31,30,31,31,30,31,30,31
	};

	split_line = split(date, '-');

	if (split_line.size() != 3)
		return (false);

	
	for (std::list<std::string>::iterator it = split_line.begin(); it != split_line.end(); ++it)
	{
		for (std::size_t i = 0; i < (*it).size(); ++i)
		{
			if (!isdigit(static_cast<unsigned char>((*it)[i])))
				return (false);
		}
	}

	std::list<std::string>::iterator	it = split_line.begin();

	std::string	year_str = *it;
	std::string	month_str = *(++it);
	std::string	day_str = *(++it);

	int	year = std::strtol(year_str.c_str(), NULL, 10);
	int	month = std::strtol(month_str.c_str(), NULL, 10);
	int	day = std::strtol(day_str.c_str(), NULL, 10);

	if (month > 12 || month < 1)
		return (false);

	int	maxDay = days[month];

	if (isLeap(year) && month == 2)
		maxDay = 29;

	if (day > maxDay || day < 1)
		return (false);

	return (year_str.size() == 4 && month_str.size() == 2 && day_str.size() == 2);
}

bool	BitcoinExchange::isTitle(const std::list<std::string>& line)
{
	if (line.size() == 2)
	{
		std::list<std::string>::const_iterator	it = line.begin();

		std::string	first = trimStr(*(it++));
		std::string	second = trimStr(*it);
		return (first == "date" && (second == "exchange_rate" || second == "value"));
	}
	return (false);
}

bool	BitcoinExchange::isValidPair(const std::list<std::string>& splited)
{
	std::pair<std::string, double>	pair;

	std::list<std::string>::const_iterator	it = splited.begin();

	if (splited.size() == 2)
	{
		std::string	spl_first = *(it++);
		std::string	spl_second = *it;

		pair.first = trimStr(spl_first);
		pair.second = std::strtod(trimStr(spl_second).c_str(), NULL);

		if (!isValidDate(pair.first))
		{
			std::cout << "Error: bad input => " << pair.first << std::endl;
			return (false);
		}
		else if (pair.second < 0.0)
		{
			std::cout << "Error: not a positive number." << std::endl;
			return (false);
		}
		else if (pair.second > 1000.0)
		{
			std::cout << "Error: too large a number." << std::endl;
			return (false);
		}
		return (true);
	}

	if (!splited.empty() && splited.size() < 2)
	{
		if (!isValidDate(trimStr(*(splited.begin()))))
			std::cout << "Error: bad input => " << *(splited.begin()) << std::endl;
	}
	else
		std::cout << "Error: bad input => too many args" << std::endl;
	return (false);
}

void	BitcoinExchange::addValue(
		const std::string& src,
		std::map<std::string, double>& data)
{
	std::string					key;
	double						value;
	std::list<std::string>	split_line;

	split_line = split(src, ',');

	if (split_line.size() != 2)
		return ;


	std::list<std::string>::iterator	it = split_line.begin();

	key = trimStr(*(it++));
	value = std::strtod(trimStr(*it).c_str(), NULL);

	if (value < 0.0 || !isValidDate(key))
		return ;

	data[key] = value;
}

void	BitcoinExchange::printEvaluation(const std::pair<std::string, double>& search,
						std::map<std::string, double>::iterator match,
						const std::map<std::string, double>& data)
{
	if (match == data.end())
	{
		--match;
		std::cout << search.first
					<< " => " << search.second
					<< " = " << match->second * search.second
					<< std::endl;
		return ;
	}

	if (match->first == search.first)
	{
		std::cout << search.first
					<< " => " << search.second
					<< " = " << match->second * search.second
					<< std::endl;
		return ;
	}

	if (match == data.begin())
	{
		std::cout << "Error: no data found for ["
				<< search.first << "]" << std::endl;
		return;
	}

	--match;
	std::cout << search.first
			<< " => " << search.second
			<< " = " << search.second * match->second
			<< std::endl;
}

/*-----BitcoinExchange methods-----*/
std::map<std::string, double>	BitcoinExchange::parseDB(const std::string& path)
{
	std::ifstream					db(path.c_str());
	std::string						line;
	std::map<std::string, double>	data;

	if (!db.is_open())
		throw	std::invalid_argument(DB_ERROR);

	if (!std::getline(db, line))
		throw std::invalid_argument(EMPTY_FILE);

	if (!isTitle(split(line, ',')))
		addValue(line, data);

	while (std::getline(db, line))
		addValue(line, data);

	return (data);
}

void	BitcoinExchange::evaluate(const std::string& input_db_name)
{
	std::ifstream					input_db(this->trimStr(input_db_name).c_str());
	std::string						line;
	std::map<std::string, double>	data;

	data = this->parseDB("./data.csv");

	if (data.empty())
		throw	std::invalid_argument(EMPTY_DATA);

	if (!input_db.is_open())
		throw	std::invalid_argument(DB_ERROR);

	if (!std::getline(input_db, line))
		throw	std::invalid_argument(EMPTY_FILE);

	std::list<std::string>		splited;
	std::pair<std::string, double>	pair;

	splited = split(line, '|');

	if (!isTitle(splited))
	{
		if (isValidPair(splited))
		{
			std::list<std::string>::iterator	it = splited.begin();

			pair.first = trimStr(*(it++));
			pair.second = std::strtod(trimStr(*it).c_str(), NULL);
			printEvaluation(pair, data.lower_bound(pair.first), data);
		}
	}

	while (std::getline(input_db, line))
	{
		splited = split(line, '|');

		if (isValidPair(splited))
		{
			std::list<std::string>::iterator	it = splited.begin();

			pair.first = trimStr(*(it++));
			pair.second = std::strtod(trimStr(*it).c_str(), NULL);
			printEvaluation(pair, data.lower_bound(pair.first), data);
		}
	}
}
