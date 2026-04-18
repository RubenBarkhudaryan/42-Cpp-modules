#include <cctype>
#include <limits>
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include "./ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(const ScalarConverter&)
{}

ScalarConverter::~ScalarConverter()
{}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter&)
{
	return (*this);
}

static int	get_prec_num(const std::string& arg)
{
	int			count = 0;
	std::size_t	i = 0;

	while (i < arg.size())
	{
		if (arg[i] == '.')
		{
			++i;
			while (i < arg.size())
			{
				if (isdigit(arg[i]))
					++count;
				++i;
			}
			break ;
		}
		++i;
	}
	return (count);
}

static bool	is_decimal_core(const std::string& arg, int len)
{
	int		i;
	bool	has_point;

	if (len <= 0)
		return (false);
	i = 0;
	has_point = false;
	if (arg[i] == '-' || arg[i] == '+')
		++i;
	if (i >= len || arg[i] == '.')
		return (false);
	while (i < len)
	{
		if (arg[i] == '.')
		{
			if (has_point || (i + 1) >= len || !isdigit(arg[i + 1]))
				return (false);
			has_point = true;
		}
		else if (!isdigit(arg[i]))
			return (false);
		++i;
	}
	return (has_point);
}

static bool	is_pseudo_literal(const std::string& arg)
{
	return (arg == "nan" || arg == "nanf"
			|| arg == "-inf" || arg == "-inff"
			|| arg == "+inf" || arg == "+inff");
}

static bool	is_double(const std::string& arg)
{
	if (arg.size() < 3)
		return (false);
	return (is_decimal_core(arg, arg.size()));
}

static bool	is_float(const std::string& arg)
{
	if (arg.size() < 4)
		return (false);
	return (is_decimal_core(arg, arg.size() - 1)
			&& arg[arg.size() - 1] == 'f');
}

static bool	is_int(const std::string& arg)
{
	std::size_t	i;

	i = 0;
	if (arg[i] == '+' || arg[i] == '-')
		++i;
	if (i >= arg.size() || !isdigit(arg[i]))
		return (false);
	while (i < arg.size())
	{
		if (!isdigit(arg[i]))
			return (false);
		++i;
	}
	return (true);
}

static bool	is_char(const std::string& arg)
{
	return (arg.size() == 1
			&& isprint(static_cast<unsigned char>(arg[0]))
			&& !isdigit(arg[0]));
}

static void	print_converted(double num, int prec_num)
{
	bool	intRange = static_cast<double>(std::numeric_limits<int>::max()) >= num
						&& static_cast<double>(std::numeric_limits<int>::min()) <= num;

	bool	floatRange = static_cast<double>(std::numeric_limits<float>::max()) >= num
						&& -static_cast<double>(std::numeric_limits<float>::max()) <= num;

	if (num < 32.0 || num > 126.0)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(num) << std::endl;

	if (!intRange)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(num) << std::endl;

	if (!floatRange)
		std::cout << "float: impossible" << std::endl;
	else
	{
		std::cout << std::fixed << std::setprecision(prec_num);
		std::cout << "float: " << static_cast<float>(num) << 'f' << std::endl;
	}

	std::cout << std::fixed << std::setprecision(prec_num);
	std::cout << "double: " << num << std::endl;
}

void	ScalarConverter::convert(const std::string& arg)
{
	if (is_pseudo_literal(arg))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		if (arg == "nan" || arg == "-inf" || arg == "+inf")
		{
			std::cout << "float: " << (arg + "f") << std::endl;
			std::cout << "double: " << arg << std::endl;
		}
		else
		{
			std::cout << "float: " << arg << std::endl;
			std::cout << "double: " << arg.substr(0, arg.size() - 1) << std::endl;
		}
	}
	else if (is_char(arg))
	{
		double	d = static_cast<double>(arg[0]);
		print_converted(d, 1);
	}
	else if (is_int(arg) || is_float(arg) || is_double(arg))
	{
		double	d = std::strtod(arg.c_str(), NULL);
		int		prec_num = get_prec_num(arg);
		print_converted(d, prec_num == 0 ? 1 : prec_num);
	}
	else
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
}
