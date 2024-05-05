/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 20:18:17 by hleung            #+#    #+#             */
/*   Updated: 2024/05/05 15:55:32 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"

template < typename Container, typename PairedContainer >
static void	makeSortedPairs(Container &container, PairedContainer &pairedContainer, bool isOdd);

template < typename PairedContainer >
static void	mergeSortPairs(PairedContainer &pairedContainer, size_t start, size_t end);

template < typename PairedContainer >
static void	merge(PairedContainer &pairedContainer, size_t start, size_t mid, size_t end);

template < typename Container, typename PairedContainer >
static void	insertion(Container &container, PairedContainer &pairedContainer, bool isOdd);

template < typename Container, typename PairedContainer >
static void	pushGreaterValuesToMain(Container &main, PairedContainer &pairedContainer);

template < typename Container >
static void binaryInsertion(Container &vec, typename Container::iterator start, typename Container::iterator end, int value);

template < typename Container, typename PairedContainer >
static void	jacobsthal(Container &main, PairedContainer &pairedContainer, bool isOdd);

template < typename Container >
static void	isSort(Container &container);

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
	if (this->_vector.size() > 10000)
		throw std::runtime_error("Error: list to long");
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

void	PmergeMe::printVector(int before)
{
	if (before) {
		std::cout << "Vector before: ";
	} else {
		std::cout << "Vector after : ";
	}
	for (std::vector<int>::iterator it = this->_vector.begin(); it != this->_vector.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void	PmergeMe::printDeque(int before)
{
	if (before) {
		std::cout << "Deque before: ";
	} else {
		std::cout << "Deque after : ";
	}
	for (std::deque<int>::iterator it = this->_deque.begin(); it != this->_deque.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void	PmergeMe::sortVector()
{
	size_t	size = this->_vector.size();
	printVector(1);
	if (size == 1) {
		printVector(0);
		return ;
	}
	bool	isOdd = size % 2 == 1;
	std::vector<std::vector<int> > pairedVector;
	makeSortedPairs(this->_vector, pairedVector, isOdd);
	if (isOdd) {
		mergeSortPairs(pairedVector, 0, pairedVector.size() - 2);
	} else {
		mergeSortPairs(pairedVector, 0, pairedVector.size() - 1);
	}
	insertion(this->_vector, pairedVector, isOdd);
	printVector(0);
	isSort(this->_vector);
}

void	PmergeMe::sortDeque()
{
	size_t	size = this->_deque.size();
	printDeque(1);
	if (size == 1) {
		printDeque(0);
		return ;
	}
	bool	isOdd = size % 2 == 1;
	std::deque<std::deque<int> > pairedDeque;
	makeSortedPairs(this->_deque, pairedDeque, isOdd);
	if (isOdd) {
		mergeSortPairs(pairedDeque, 0, pairedDeque.size() - 2);
	} else {
		mergeSortPairs(pairedDeque, 0, pairedDeque.size() - 1);
	}
	insertion(this->_deque, pairedDeque, isOdd);
	printDeque(0);
	isSort(this->_deque);
}

/*------------------------- Static Helper Functions --------------------------*/

template < typename Container, typename PairedContainer >
static void	makeSortedPairs(Container &container, PairedContainer &pairedContainer, bool isOdd)
{
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

template < typename Container, typename PairedContainer >
static void	insertion(Container &container, PairedContainer &pairedContainer, bool isOdd) {
	(void)container;
	Container	main;
	pushGreaterValuesToMain(main, pairedContainer);
	size_t	pcSize = pairedContainer.size();

	if (pcSize == 2) {
		binaryInsertion(main, main.begin(), main.end(), pairedContainer[pcSize - 1][0]);
	} else {
		jacobsthal(main, pairedContainer, isOdd);
	}
	std::copy(main.begin(), main.end(), container.begin());
}

template < typename Container, typename PairedContainer >
static void	pushGreaterValuesToMain(Container &main, PairedContainer &pairedContainer)
{
	typename PairedContainer::iterator	i = pairedContainer.begin();
	for (; i != pairedContainer.end(); i++) {
		for (typename Container::iterator j = (*i).begin(); j != (*i).end(); j++) {
			if (i == pairedContainer.begin()) {
				main.push_back(*j);
				continue ;
			}
			if (j != (*i).begin())
				main.push_back(*j);
		}
	}
}

template < typename Container >
static void binaryInsertion(Container &vec, typename Container::iterator start, typename Container::iterator end, int value)
{
    if (start != end) {
        typename Container::iterator mid = start + std::distance(start, end) / 2;
        if (value < *mid) {
            binaryInsertion(vec, start, mid, value);
        } else {
            binaryInsertion(vec, mid + 1, end, value);
        }
    } else {
        vec.insert(end, value);
    }
}

template < typename Container, typename PairedContainer >
static void	jacobsthal(Container &main, PairedContainer &pairedContainer, bool isOdd)
{
	size_t	jacobsthal[13] = {1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461};
	size_t	lastPair = pairedContainer.size() - 1;
	size_t	pc = 0, k, j;
	for (j = 1; j < 13 && jacobsthal[j] <= pairedContainer.size(); ++j) {
		for (k = jacobsthal[j] - 1; k >= jacobsthal[j - 1]; --k) {
			if (k == lastPair && isOdd) {
				binaryInsertion(main, main.begin(), main.end(), pairedContainer[k][0]);
			} else {
				typename Container ::iterator	val = main.begin() + jacobsthal[j] + jacobsthal[j - 1] - 1;
				binaryInsertion(main, main.begin(), val, pairedContainer[k][0]);
			}
			pc++;
		}
	}
	pc++;
	for (; pc <= lastPair; ++pc) {
		if (pc == lastPair && isOdd) {
			binaryInsertion(main, main.begin(), main.end(), pairedContainer[pc][0]);
		} else {
			typename Container ::iterator	val = main.begin() + (pc * 2);
			binaryInsertion(main, main.begin(), val, pairedContainer[pc][0]);
		}
	}
}

template < typename Container >
static void	isSort(Container &container)
{
	for (size_t i = 1; i < container.size(); ++i)
	{
		if (container[i] <= container[i - 1]) {
			std::cout << "Not sorted!" << std::endl;
			std::cout << "Size: " << container.size() << std::endl;
			return;
		}
	}
	std::cout << "Sorted!" << std::endl;
	std::cout << "Size: " << container.size() << std::endl;
}
