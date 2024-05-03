/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 20:18:17 by hleung            #+#    #+#             */
/*   Updated: 2024/05/02 22:09:58 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"

template < typename Container >
static void	makeSortedPairs(Container &container);

/*------------------------------- Constructors -------------------------------*/

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(char **args)
{
	for (int i = 1; args[i]; ++i) {
		std::string str = args[i];
		if (str.empty() || str.find_first_not_of("0123456789") != str.npos)
			throw std::runtime_error("Error: Invalid input");
		double	value = strtod(args[i], NULL);
		if (value < 0 || value > std::numeric_limits<int>::max())
			throw std::runtime_error("Error: Number out of range");
		this->_vector.push_back(static_cast<int>(value));
		this->_deque.push_back(static_cast<int>(value));
	}
}

PmergeMe::PmergeMe(const PmergeMe &src) {*this = src;}

/*-------------------------------- Destructor --------------------------------*/

PmergeMe::~PmergeMe() {}

/*--------------------------------- Overload ---------------------------------*/

PmergeMe	&PmergeMe::operator=(const PmergeMe &rhs)
{
	if (this != &rhs)
	{
		this->_vector = rhs._vector;
		this->_deque = rhs._deque;
	}
	return *this;
}

/*----------------------------- Member Functions -----------------------------*/

void	PmergeMe::print()
{
	std::cout << "Vector before: ";
	for (std::vector<int>::iterator it = this->_vector.begin(); it != this->_vector.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout << "Deque before:  ";
	for (std::deque<int>::iterator it = this->_deque.begin(); it != this->_deque.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void	PmergeMe::sort()
{
	makeSortedPairs(this->_vector);
	print();
}

/*------------------------- Static Helper Functions --------------------------*/

template < typename Container >
static void	makeSortedPairs(Container &container)
{
	
	typename Container::iterator it = container.begin();
	typename Container::iterator end = container.end();

	if (container.size() % 2 == 1) 
		end--;
	while (it != end)
	{
		if (*it > *(it + 1)) {
			int	tmp = *it;
			*it = *(it + 1);
			*(it + 1) = tmp;
		}
		it += 2;
	}
}

