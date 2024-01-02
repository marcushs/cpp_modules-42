/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:36:25 by hleung            #+#    #+#             */
/*   Updated: 2024/01/02 20:15:40 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <exception>
# include <iostream>

template < typename T >
class Array
{

	class OutOfRangeException : public std::exception
	{
	public:
		const char* what() const throw() {return "Index out of range!";}
	};

public:
	Array<T>();
	Array<T>(const unsigned int n);
	Array<T>(const Array<T> &src);
	~Array<T>();

	Array<T>	&operator=(const Array<T> &rhs);
	T	&operator[](const unsigned int rhs);

	unsigned int size() const;

private:
	T	*_data;
	unsigned int	_size;
};

template < typename T >
std::ostream	&operator<<(std::ostream &o, const Array<T> &rhs);

#include "../template/Array.tpp" //https://isocpp.org/wiki/faq/templates#templates-defn-vs-decl, https://stackoverflow.com/questions/495021/why-can-templates-only-be-implemented-in-the-header-file

#endif
