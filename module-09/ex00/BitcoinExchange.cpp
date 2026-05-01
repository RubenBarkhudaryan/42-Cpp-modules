#include <fstream>
#include <iostream>
#include <stdexcept>
#include <cctype>
#include <cstdlib>
#include <map>
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
	return (line.size() == 2
			&& line[0] == "date"
			&& (line[1] == "exchange_rate" || line[1] == "value"));
}

void	addValue(
		const std::string& src,
		std::map<std::string, float>& data,
		char separator,
		bool is_input)
{
	std::string					key;
	float						value;
	char						*end;
	std::vector<std::string>	split_line;

	split_line = split(src, separator);

	if (split_line.size() != 2)
		return ;

	key = trimStr(split_line[0]);
	value = std::strtof(trimStr(split_line[1]).c_str(), &end);

	if (*end != '\0' || value < 0.0f || !isValidDate(key))
		return ;

	if (is_input && (value < 0.0f || value > 1000.0f))
		return ;

	data[key] = value;
}

void	printEvaluation(std::map<std::string, float>::iterator search,
						std::map<std::string, float>::iterator match,
						const std::map<std::string, float>& data)
{
	if (match == data.end())
	{
		--match;
		std::cout << search->first
					<< " => " << search->second
					<< " = " << match->second * search->second
					<< std::endl;
		return ;
	}

	if (match->first == search->first)
	{
		std::cout << search->first
					<< " => " << search->second
					<< " = " << match->second * search->second
					<< std::endl;
		return ;
	}

	if (match == data.begin())
	{
		std::cout << "Error: no data found for ["
				<< search->first << "]" << std::endl;
		return;
	}

	--match;
	std::cout << search->first
			<< " => " << search->second
			<< " = " << search->second * match->second
			<< std::endl;
}

/*-----BitcoinExchange methods-----*/
std::map<std::string, float>	BitcoinExchange::parseDB(const std::string& path, char separator, bool is_input)
{
	std::ifstream					db(path.c_str());
	std::string						line;
	std::map<std::string, float>	data;

	if (!db.is_open())
		throw	std::invalid_argument(DB_ERROR);

	if (!std::getline(db, line))
		throw std::invalid_argument(EMPTY_FILE);

	if (!isTitle(split(line, separator)))
		addValue(line, data, separator, is_input);

	while (std::getline(db, line))
		addValue(line, data, separator, is_input);

	return (data);
}

void	BitcoinExchange::evaluate(const std::string& input_db_name)
{
	std::map<std::string, float>	input_data;
	std::map<std::string, float>	data;

	data = this->parseDB("./data.csv", ',', false);

	if (data.empty())
		throw	std::invalid_argument(EMPTY_DATA);

	input_data = this->parseDB(input_db_name, '|', true);

	if (input_data.empty())
		throw	std::invalid_argument(EMPTY_DATA);

	for (std::map<std::string, float>::iterator it = input_data.begin(); it != input_data.end(); ++it)
		printEvaluation(it, data.lower_bound(it->first), data);
}
