#ifndef	FIXED_HPP

# define FIXED_HPP

# include <iostream>

class	Fixed
{

	private:
		int					val;
		static const int	fractional_bits;

	public:
		/*-----Fixed ctor/dtor-----*/
		Fixed();
		Fixed(const int val);
		Fixed(const float val);
		Fixed(const Fixed& other);
		~Fixed();

		/*-----Fixed operators-----*/
		Fixed&	operator=(const Fixed& other);

		/*-----Fixed methods-----*/
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream&	operator<<(std::ostream& os, const Fixed& obj);

#endif //FIXED_HPP
