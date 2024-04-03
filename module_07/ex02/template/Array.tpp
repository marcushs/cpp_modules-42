/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:39:39 by hleung            #+#    #+#             */
/*   Updated: 2024/01/02 19:49:39 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

/*------------------------------- Constructors -------------------------------*/

template < typename T >
Array<T>::Array(void) : _size(0)
{
	this->_data = new T[this->_size];
}

template < typename T >
Array<T>::Array(unsigned int n) : _size(n)
{
	this->_data = new T[this->_size];
}

template < typename T >
Array<T>::Array(const Array<T> &src)
{
	*this = src;
}

/*-------------------------------- Destructor --------------------------------*/

template < typename T >
Array<T>::~Array()
{
	delete [] this->_data;
}

/*--------------------------------- Overload ---------------------------------*/

template < typename T >
Array<T>	&Array<T>::operator=(const Array<T> &rhs)
{
	if (this == &rhs)
		return (*this);
	this->_size = rhs._size;
	if (this->_data)
		delete [] this->_data;
	this->_data = new T[this->_size];
	for(unsigned int i = 0; i < this->_size; i++)
		this->_data[i] = rhs._data[i];
	return (*this);
}

template < typename T >
T	&Array<T>::operator[](const unsigned int rhs)
{
	if (rhs >= this->_size)
		throw Array::OutOfRangeException();
	return this->_data[rhs];
}

template < typename T >
std::ostream	&operator<<(std::ostream &o, const Array<T> &rhs)
{
	o << &rhs;
	return o;
}

/*----------------------------- Member Functions -----------------------------*/

template < typename T >
unsigned int	Array<T>::size() const 
{
	return this->_size;
}

#endif
