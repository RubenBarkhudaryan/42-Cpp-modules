#ifndef ARRAY_HPP

# define ARRAY_HPP

# include <cstddef>
# include <exception>

template <typename T>
class	Array
{
	private:
		T				*_data;
		unsigned int	_size;

	public:
		/*-----Array ctors/dtor-----*/
		Array();
		Array(unsigned int n);
		Array(const Array<T>& other);
		~Array();

		/*-----Array operators-----*/
		Array<T>&	operator=(const Array<T>& other);
		const T&	operator[](unsigned int idx) const;
		T&			operator[](unsigned int idx);

		/*-----Array methods-----*/
		unsigned int	size(void) const;
};

template <typename T>
Array<T>::Array() : _data(NULL), _size(0)
{}

template <typename T>
Array<T>::Array(unsigned int n) : _data(new T[n]), _size(n)
{}

template <typename T>
Array<T>::Array(const Array<T>& other) : _data(NULL), _size(other._size)
{
	this->_data = new T[this->_size];
	for (unsigned int i = 0; i < this->_size; ++i)
		this->_data[i] = other._data[i];
}

template <typename T>
Array<T>::~Array()
{
	delete[] this->_data;
}

template <typename T>
Array<T>&	Array<T>::operator=(const Array<T>& other)
{
	if (this != &other)
	{
		delete[] this->_data;
		this->_size = other._size;
		this->_data = new T[this->_size];
		for (unsigned int i = 0; i < this->_size; ++i)
			this->_data[i] = other._data[i];
	}
	return (*this);
}

template <typename T>
T&	Array<T>::operator[](unsigned int idx)
{
	if (idx >= this->_size)
		throw std::out_of_range("Invalid index");
	return (this->_data[idx]);
}

template <typename T>
const T&	Array<T>::operator[](unsigned int idx) const
{
	if (idx >= this->_size)
		throw std::out_of_range("Invalid index");
	return (this->_data[idx]);
}

template <typename T>
unsigned int	Array<T>::size(void) const
{
	return (this->_size);
}

#endif //ARRAY_HPP