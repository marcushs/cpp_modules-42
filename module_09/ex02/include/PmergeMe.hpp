/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 20:17:47 by hleung            #+#    #+#             */
/*   Updated: 2024/05/02 18:06:45 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <iostream>
# include <limits>
# include <string>
# include <vector>
# include <deque>
# include <cstdlib>

class PmergeMe
{
public:
	PmergeMe(char **args);
	~PmergeMe();
	void	print();
	void	sort();
	
private:
	PmergeMe();
	PmergeMe(const PmergeMe &src);
	PmergeMe	&operator=(const PmergeMe &rhs);
	std::vector<int>	_vector;
	std::deque<int>		_deque;
};




#endif
