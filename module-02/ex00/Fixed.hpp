#ifndef	FIXED_HPP

# define FIXED_HPP

class	Fixed
{

	private:
		int					val;
		static const int	fractional_bits;

	public:
		/*-----Fixed ctor/dtor-----*/
		Fixed();
		Fixed(const Fixed& other);
		~Fixed();

		/*-----Fixed operators-----*/
		Fixed&	operator=(const Fixed& other);

		/*-----Fixed methods-----*/
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif //FIXED_HPP
