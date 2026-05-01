#ifndef BITCOIN_EXCHANGE_HPP

# define BITCOIN_EXCHANGE_HPP

# define DB_ERROR "Error: unable to open database for evaluation. Make sure that database is in current directory."
# define EMPTY_FILE "Error: given database file is empty."
# define EMPTY_DATA "Error: no valid data in given database file."

# include <map>
# include <string>
# include <vector>
# include <utility>

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
		std::map<std::string, double>	parseDB(const std::string& path);
};

std::string					trimStr(const std::string& input);
std::vector<std::string>	split(const std::string& str, char target);
bool						isLeap(int year);
bool						isValidDate(const std::string& date);
bool						isValidPair(const std::vector<std::string>& splited);
bool						isTitle(const std::vector<std::string>& line);
void						addValue(
								const std::string& src,
								std::map<std::string, double>& data);
void						printEvaluation(
								const std::pair<std::string, double>& search,
								std::map<std::string, double>::iterator match,
								const std::map<std::string, double>& data);

#endif //BITCOIN_EXCHANGE_HPP