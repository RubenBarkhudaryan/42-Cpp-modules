#include <cmath>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include "./Span.hpp"

Span::Span() :
	n(0),
	offset(0),
	data()
{}

Span::Span(unsigned int n) :
	n(n),
	offset(0),
	data(n)
{}

Span::Span(const Span& other) :
	n(other.n),
	offset(other.offset)
{
	this->data.reserve(this->n);
	for (unsigned int i = 0; i < this->offset; ++i)
		this->data[i] = other.data[i];
}

Span::~Span()
{}

Span&	Span::operator=(const Span& other)
{
	if (this != &other)
	{
		this->n = other.n;
		this->offset = other.offset;
		this->data.clear();
		this->data.reserve(this->n);
		for (unsigned int i = 0; i < this->offset; ++i)
			this->data[i] = other.data[i];
	}
	return (*this);
}

void	Span::addNumber(int num)
{
	if ((this->offset + 1) > this->n)
		throw std::length_error(SPAN_MAX_REACHED);
	this->data[this->offset] = num;
	++(this->offset);
}

int	Span::shortestSpan(void)
{
	if (this->offset <= 1)
		throw std::length_error(SPAN_FEW_ELEMS);

	std::sort(this->data.begin(), this->data.begin() + this->offset);

	int	shortest = std::abs(this->data[0] - this->data[1]);

	for (unsigned int i = 1; i < this->offset - 1; ++i)
	{
		int	curr = std::abs(this->data[i] - this->data[i + 1]);
		if (curr < shortest)
			shortest = curr;
	}
	return (shortest);
}

int	Span::longestSpan(void)
{
	if (this->offset <= 1)
		throw std::length_error(SPAN_FEW_ELEMS);

	std::sort(this->data.begin(), this->data.begin() + this->offset);

	return (this->data[this->offset - 1] - this->data[0]);
}
