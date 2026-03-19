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
		Fixed(const int val);
		Fixed(const float val);
		Fixed(const Fixed& other);
		~Fixed();

		/*-----Fixed operators-----*/
		Fixed&	operator=(const Fixed& other);
		bool	operator<(const Fixed& other) const;
		bool	operator>(const Fixed& other) const;
		bool	operator<=(const Fixed& other) const;
		bool	operator>=(const Fixed& other) const;
		bool	operator==(const Fixed& other) const;
		bool	operator!=(const Fixed& other) const;

		Fixed	operator+(const Fixed& other);
		Fixed	operator-(const Fixed& other);
		Fixed	operator*(const Fixed& other);
		Fixed	operator/(const Fixed& other);

		Fixed&	operator++(void);
		Fixed&	operator--(void);
		Fixed	operator++(int);
		Fixed	operator--(int);

		/*-----Fixed methods-----*/
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

		/*-----Fixed static functions-----*/
		static Fixed&		min(Fixed& f1, Fixed& f2);
		static Fixed&		max(Fixed& f1, Fixed& f2);
		static const Fixed&	min(const Fixed& f1, const Fixed& f2);
		static const Fixed&	max(const Fixed& f1, const Fixed& f2);
};

std::ostream&	operator<< (std::ostream& os, const Fixed& obj);

#endif //FIXED_HPP
