/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 20:18:17 by hleung            #+#    #+#             */
/*   Updated: 2024/05/04 11:07:36 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"

template < typename Container, typename PairedContainer >
static void	makeSortedPairs(Container &container, PairedContainer &pairedContainer);

template < typename PairedContainer >
void mergeSortPairs(PairedContainer &pairedContainer, size_t start, size_t end);

bool compare(const std::vector<int> &a, const std::vector<int> &b);

template < typename PairedContainer >
void	merge(PairedContainer &pairedContainer, size_t start, size_t mid, size_t end);

template < typename Container, typename PairedContainer >
static void	insertion(Container &container, PairedContainer &pairedContainer);


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
		mergeSortPairs(pairedVector, 0, pairedVector.size() - 2);
	} else {
		mergeSortPairs(pairedVector, 0, pairedVector.size() - 1);
	}
	std::cout << "pairedVector: ";
	for (std::vector<std::vector<int> >::iterator i = pairedVector.begin(); i != pairedVector.end(); ++i) {
		for (std::vector<int>::iterator j =  (*i).begin(); j != (*i).end(); ++j) {
			std::cout << *j << " ";
		}
	}
	std::cout << std::endl;
	// insertion(this->_vector, pairedVector);
}

void	PmergeMe::sortDeque()
{
	print();
	std::deque<std::deque<int> > pairedDeque;
	makeSortedPairs(this->_deque, pairedDeque);
	if (this->_deque.size() % 2 == 1) {
		mergeSortPairs(pairedDeque, 0, pairedDeque.size() - 2);
	} else {
		mergeSortPairs(pairedDeque, 0, pairedDeque.size() - 1);
	}
	std::cout << "pairedDeque: ";
	for (std::deque<std::deque<int> >::iterator i = pairedDeque.begin(); i != pairedDeque.end(); ++i) {
		for (std::deque<int>::iterator j =  (*i).begin(); j != (*i).end(); ++j) {
			std::cout << *j << " ";
		}
	}
	std::cout << std::endl;
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

template < typename PairedContainer >
static void	mergeSortPairs(PairedContainer &pairedContainer, size_t start, size_t end) {
    if (start < end) {
        size_t middle = start + (end - start) / 2;
        mergeSortPairs(pairedContainer, start, middle);
        mergeSortPairs(pairedContainer, middle + 1, end);
		merge(pairedContainer, start, middle, end);
    }
}

template < typename Container, typename PairedContainer >
static void	insertion(Container &container, PairedContainer &pairedContainer) {
	(void)container;
	Container	main;
	Container	pend;
	typename PairedContainer::iterator	i = pairedContainer.begin();
	for (; i != pairedContainer.end(); i++) {
		for (typename Container::iterator j = (*i).begin(); j != (*i).end(); j++) {
			if (i == pairedContainer.begin()) {
				main.push_back(*j);
			} else if (j != (*i).begin()) {
				main.push_back(*j);
			} else {
				pend.push_back(*j);
			}
		}
	}
	std::cout << "Main: ";
	for (typename Container::iterator it = main.begin(); it != main.end(); it++){
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout << "Pend: ";
	for (typename Container::iterator it = pend.begin(); it != pend.end(); it++){
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

template < typename PairedContainer >
static void	merge(PairedContainer &pairedContainer, size_t start, size_t mid, size_t end)
{
	PairedContainer	tmp(end - start + 1);
	size_t	i = start, j = mid + 1, k = 0;

	while (i <= mid && j <= end) {
		if (pairedContainer[i][1] < pairedContainer[j][1]) {
			tmp[k++] = pairedContainer[i++];
		} else {
			tmp[k++] = pairedContainer[j++];
		}
	}
	while (i <= mid) {
		tmp[k++] = pairedContainer[i++];
	}
	while (j <= end) {
		tmp[k++] = pairedContainer[j++];
	}
	for (size_t p = 0; p < tmp.size(); ++p) {
		pairedContainer[start + p] = tmp[p];
	}
}
