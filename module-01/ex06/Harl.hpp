#ifndef	HARL_HPP

# define HARL_HPP

# define DEBUG		"I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\nI really do!"
# define INFO		"I cannot believe adding extra bacon costs more money.\nYou didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!"
# define WARNING	"I think I deserve to have some extra bacon for free.\nI've been coming for years, whereas you started working here just last month."
# define ERROR		"This is unacceptable! I want to speak to the manager now."
# define DEFAULT	"[ Probably complaining about insignificant problems ]"

# define RESET		"\033[0m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define CYAN		"\033[36m"

# include <string>

class	Harl
{
	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
		void	call(int pos);

	public:
		void	complain(std::string level);
		void	filter(int levels);
};

#endif //HARL_HPP
