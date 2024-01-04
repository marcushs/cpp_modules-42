/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:39:59 by hleung            #+#    #+#             */
/*   Updated: 2024/01/04 15:41:35 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP
# include <vector>
# include <iterator>

class Span
{

	class SpanIsFullException : public std::exception
	{
	public:
		const char* what() const throw() {return "Span is full, cannot add number";}
	};

	class NoDistanceException : public std::exception
	{
	public:
		const char* what() const throw() {return "Less than 2 numbers, no span calculated";}
	};

public:
	Span(const unsigned int &N);
	Span(const Span &src);
	~Span();

	Span	&operator=(const Span &rhs);

	std::vector<int>	&getNumbers();
	unsigned int		getCount() const;

	void	addNumber(const int &n);
	void	addNumber(const std::vector<int>::const_iterator &first, const std::vector<int>::const_iterator &second);
	int		shortestSpan();
	int		longestSpan();
private:
	Span();
	const unsigned int	_count;
	std::vector<int>	_numbers;
};

#endif
