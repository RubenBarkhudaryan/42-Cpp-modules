#ifndef WHATEVER_HPP

# define WHATEVER_HPP

template <typename T>
void	swap(T& val1, T& val2)
{
	T	val3;

	val3 = val1;
	val1 = val2;
	val2 = val3;
}

template <typename T>
T	min(const T& val1, const T& val2)
{
	return (val1 >= val2 ? val2 : val1);
}

template <typename T>
T	max(const T& val1, const T& val2)
{
	return (val1 <= val2 ? val2 : val1);
}

#endif //WHATEVER_HPP