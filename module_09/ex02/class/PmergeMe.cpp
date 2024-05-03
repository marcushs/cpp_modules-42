/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 20:18:17 by hleung            #+#    #+#             */
/*   Updated: 2024/05/03 16:08:00 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"

template < typename Container, typename PairedContainer >
static void	makeSortedPairs(Container &container, PairedContainer &pairedContainer);

void recursiveSort(std::vector<std::vector<int> >& vec, size_t start, size_t end);
bool compare(const std::vector<int>& a, const std::vector<int>& b);

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
		for (std::vector<int>::iterator it = this->_vector.begin(); it != this->_vector.end(); ++it) {
			if (*it == static_cast<int>(value))
				throw std::runtime_error("Error: Same number more than once");
		}
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

void	PmergeMe::sortVector()
{
	print();
	std::vector<std::vector<int> > pairedVector;
	makeSortedPairs(this->_vector, pairedVector);
	if (this->_vector.size() % 2 == 1) {
		recursiveSort(pairedVector, 0, pairedVector.size() - 2);
	} else {
		recursiveSort(pairedVector, 0, pairedVector.size() - 1);
	}
	std::cout << "pairedVector: ";
	for (std::vector<std::vector<int> >::iterator i = pairedVector.begin(); i != pairedVector.end(); ++i) {
		for (std::vector<int>::iterator j =  (*i).begin(); j != (*i).end(); ++j) {
			std::cout << *j << " ";
		}
	}
}

/*------------------------- Static Helper Functions --------------------------*/

template < typename Container, typename PairedContainer >
static void	makeSortedPairs(Container &container, PairedContainer &pairedContainer)
{
	bool	isOdd = container.size() % 2 == 1;
	typename Container::iterator it = container.begin();
	typename Container::iterator end = (isOdd) ? (container.end()) - 1 : container.end();

	while (it != end)
	{
		Container	pair;
		if (*it > *(it + 1)) {
			int	tmp = *it;
			*it = *(it + 1);
			*(it + 1) = tmp;
		}
		pair.push_back(*it);
		pair.push_back(*(it + 1));
		pairedContainer.push_back(pair);
		it += 2;
	}
	if (isOdd) {
		Container	last;
		last.push_back(container.back());
		pairedContainer.push_back(last);
	}
}

void recursiveSort(std::vector<std::vector<int> >& vec, size_t start, size_t end) {
    if (start < end) {
        size_t middle = start + (end - start) / 2;
        recursiveSort(vec, start, middle);
        recursiveSort(vec, middle + 1, end);
        std::inplace_merge(vec.begin() + start, vec.begin() + middle + 1, vec.begin() + end + 1, compare);
    }
}

bool compare(const std::vector<int>& a, const std::vector<int>& b) {
    return a[1] < b[1];
}

