#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <sstream>
# include <vector>
# include <deque>
# include <algorithm>
# include <stdexcept>
# include <cstdlib>
# include <climits>
# include <ctime>

class PmergeMe
{
	public:
		/*-----ctors/dtor-----*/
		PmergeMe();
		PmergeMe(const PmergeMe&);
		~PmergeMe();

		/*-----operators-----*/
		PmergeMe&	operator=(const PmergeMe&);

		/*-----public methods-----*/
		void	parse(char **argv);

		void	sortVector(std::vector<int>& vec);
		void	sortDeque(std::deque<int>& deq);

		void	printBefore(void) const;
		void	printAfter(void) const;

		std::vector<int>&	getVector(void);
		std::deque<int>&	getDeque(void);


	private:
		std::vector<int>	_vector;
		std::deque<int>		_deque;

		int		parseInt(const std::string& str);

		void	insertVector(std::vector<int>& vec, int value);
		void	insertDeque(std::deque<int>& deq, int value);
};

#endif