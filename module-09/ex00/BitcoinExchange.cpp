#include <fstream>
#include <iostream>
#include <stdexcept>
#include <cctype>
#include <cstdlib>
#include <map>
#include <utility>
#include <vector>
#include <string>

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
std::string	trimStr(const std::string& input)
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
	if (end > start)
		return (input.substr(start, end - start + 1));
	return ("");
}

std::vector<std::string>	split(const std::string& str, char target)
{
	std::size_t					i;
	std::size_t					j;
	std::size_t					size;
	std::vector<std::string>	result;

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

bool	isLeap(int year)
{
	return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

bool	isValidDate(const std::string& date)
{
	std::vector<std::string>	split_line;
	static int	days[] = {
		0,31,28,31,30,31,30,31,31,30,31,30,31
	};

	split_line = split(date, '-');

	if (split_line.size() != 3)
		return (false);

	for (std::size_t i = 0; i < split_line.size(); ++i)
	{
		for (std::size_t j = 0; j < split_line[i].size(); ++j)
		{
			if (!isdigit(static_cast<unsigned char>(split_line[i][j])))
				return (false);
		}
	}

	int	year = std::strtol(split_line[0].c_str(), NULL, 10);
	int	month = std::strtol(split_line[1].c_str(), NULL, 10);
	int	day = std::strtol(split_line[2].c_str(), NULL, 10);

	if (month > 12 || month < 1)
		return (false);

	int	maxDay = days[month];

	if (isLeap(year) && month == 2)
		maxDay = 29;

	if (day > maxDay || day < 1)
		return (false);

	return (split_line[0].size() == 4 && split_line[1].size() == 2 && split_line[2].size() == 2);
}

bool	isTitle(const std::vector<std::string>& line)
{
	if (line.size() == 2)
	{
		std::string	first = trimStr(line[0]);
		std::string	second = trimStr(line[1]);
		return (first == "date" && (second == "exchange_rate" || second == "value"));
	}
	return (false);
}

bool	isValidPair(const std::vector<std::string>& splited)
{
	std::pair<std::string, double>	pair;

	if (splited.size() == 2)
	{
		pair.first = trimStr(splited[0]);
		pair.second = std::strtod(trimStr(splited[1]).c_str(), NULL);

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
		if (!isValidDate(trimStr(splited[0])))
			std::cout << "Error: bad input => " << splited[0] << std::endl;
	}
	else
		std::cout << "Error: bad input => too many args" << std::endl;
	return (false);
}

void	addValue(
		const std::string& src,
		std::map<std::string, double>& data)
{
	std::string					key;
	double						value;
	std::vector<std::string>	split_line;

	split_line = split(src, ',');

	if (split_line.size() != 2)
		return ;

	key = trimStr(split_line[0]);
	value = std::strtod(trimStr(split_line[1]).c_str(), NULL);

	if (value < 0.0 || !isValidDate(key))
		return ;

	data[key] = value;
}

void	printEvaluation(const std::pair<std::string, double>& search,
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
	std::ifstream					input_db(input_db_name.c_str());
	std::string						line;
	std::map<std::string, double>	data;

	data = this->parseDB("./data.csv");

	if (data.empty())
		throw	std::invalid_argument(EMPTY_DATA);

	if (!input_db.is_open())
		throw	std::invalid_argument(DB_ERROR);

	if (!std::getline(input_db, line))
		throw	std::invalid_argument(EMPTY_FILE);

	std::vector<std::string>		splited;
	std::pair<std::string, double>	pair;

	splited = split(line, '|');

	if (!isTitle(splited))
	{
		if (isValidPair(splited))
		{
			pair.first = trimStr(splited[0]);
			pair.second = std::strtod(splited[1].c_str(), NULL);
			printEvaluation(pair, data.lower_bound(pair.first), data);
		}
	}

	while (std::getline(input_db, line))
	{
		splited = split(line, '|');

		if (isValidPair(splited))
		{
			pair.first = trimStr(splited[0]);
			pair.second = std::strtod(splited[1].c_str(), NULL);
			printEvaluation(pair, data.lower_bound(pair.first), data);
		}
	}
}
