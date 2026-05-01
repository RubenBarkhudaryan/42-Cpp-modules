#ifndef BITCOIN_EXCHANGE_HPP

# define BITCOIN_EXCHANGE_HPP

# define DB_ERROR "Error: unable to open database for evaluation. Make sure that database is in current directory."
# define EMPTY_FILE "Error: given database file is empty."
# define EMPTY_DATA "Error: no valid data in given database file."

# include <map>
# include <string>
# include <vector>

class	BitcoinExchange
{
	public:
		/*-----BitcoinExchange ctors/dtor-----*/
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange&);
		~BitcoinExchange();

		/*-----BitcoinExchange operators-----*/
		BitcoinExchange&	operator=(const BitcoinExchange&);

		/*-----BitcoinExchange methods-----*/
		void	evaluate(const std::string& input_db_name);
		std::map<std::string, float>	parseDB(const std::string& path, char separator, bool is_input);
};

std::string					trimStr(const std::string& input);
std::vector<std::string>	split(const std::string& str, char target);
bool						isLeap(int year);
bool						isValidDate(const std::string& date);
bool						isTitle(const std::vector<std::string>& line);
void						addValue(
								const std::string& src,
								std::map<std::string, float>& data,
								char separator, bool is_input);
void						printEvaluation(
								std::map<std::string, float>::iterator search,
								std::map<std::string, float>::iterator match,
								const std::map<std::string, float>& data);

#endif //BITCOIN_EXCHANGE_HPP