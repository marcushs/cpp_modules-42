/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:39:30 by hleung            #+#    #+#             */
/*   Updated: 2024/01/04 16:05:41 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Span.hpp"
#include <algorithm>

/*------------------------------- Constructors -------------------------------*/

Span::Span() : _count(0) {}

Span::Span(const unsigned int &N) : _count(N) {}

Span::Span(const Span &src) : _count(src._count) { *this = src; }


/*-------------------------------- Destructor --------------------------------*/

Span::~Span() {}

/*--------------------------------- Overload ---------------------------------*/

Span	&Span::operator=(const Span &rhs)
{
	if (this == &rhs)
		return *this;
	this->_numbers = std::vector<int>(rhs._numbers.begin(), rhs._numbers.end());
	return (*this);
}

/*---------------------------------- Getter ----------------------------------*/

std::vector<int>	&Span::getNumbers() { return this->_numbers;}

unsigned int	Span::getCount() const { return this->_count;}

/*----------------------------- Member Functions -----------------------------*/

void	Span::addNumber(const int &n)
{
	if (this->_numbers.size() >= this->_count)
		throw Span::SpanIsFullException();
	this->_numbers.push_back(n);
}

void	Span::addNumber(const std::vector<int>::const_iterator &first, const std::vector<int>::const_iterator &second)
{
	if ((std::distance(first, second) + this->_numbers.size()) >= this->_count)
		throw Span::SpanIsFullException();
	this->_numbers.assign(first, second);
}


int	Span::shortestSpan()
{
	size_t	size = this->_numbers.size();
	if (size < 2)
		throw Span::NoDistanceException();
	std::vector<int>	tmp = this->_numbers;
	std::sort(tmp.begin(), tmp.end());
	int span = -1;
	for (size_t i = 0; i < size - 2; i++)
		if (span < 0 || abs(tmp[i] - tmp[i + 1]) < span)
			span = abs(tmp[i] - tmp[i + 1]);
	return span;
}

int	Span::longestSpan()
{
	if (this->_numbers.size() < 2)
		throw Span::NoDistanceException();
 	std::vector<int>::iterator min = std::min_element(this->_numbers.begin(), this->_numbers.end());
 	std::vector<int>::iterator max = std::max_element(this->_numbers.begin(), this->_numbers.end());
	return (abs(*max - *min));
}
