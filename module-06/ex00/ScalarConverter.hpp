#ifndef SCALAR_CONVERTER

# define SCALAR_CONVERTER

# include <string>

class	ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter&);
		~ScalarConverter();
		ScalarConverter&	operator=(const ScalarConverter&);

	public:
		static void	convert(const std::string& arg);
};

#endif //SCALAR_CONVERTER