/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:00:00 by hleung            #+#    #+#             */
/*   Updated: 2024/01/05 16:02:32 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/MutantStack.hpp"
#include <iostream>
#include <list>

int	main(void)
{
	{
		MutantStack<int> mstack;
		mstack.push(5); // [5]
		mstack.push(17); // [5, 17]
		std::cout << "Top of mstack : ";
		std::cout << mstack.top() << std::endl; // 17
		mstack.pop(); // [5]
		std::cout << "Size of mstack is : ";
		std::cout << mstack.size() << std::endl; // 1
		mstack.push(3); //[5, 3]
		mstack.push(5); // [5, 3, 5]
		mstack.push(737); // [5, 3, 5, 737];
		mstack.push(0); // [5, 3, 5, 737, 0];
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
		size_t size = s.size();
		for (size_t i = 0; i < size; i++)
		{
			std::cout << "Top of s is : "; 
			std::cout << s.top() << std::endl; 
			s.pop();
		}
		// 0 -> 737 -> 5 -> 3 -> 5
	}

	// {
	// 	std::list<int> list;
	// 	list.push_back(5); // [5]
	// 	list.push_back(17); // [5, 17]
	// 	std::cout << "Top of list : ";
	// 	std::cout << list.back() << std::endl; // 17
	// 	list.pop_back(); // [5]
	// 	std::cout << "Size of list is : ";
	// 	std::cout << list.size() << std::endl; // 1
	// 	list.push_back(3); //[5, 3]
	// 	list.push_back(5); // [5, 3, 5]
	// 	list.push_back(737); // [5, 3, 5, 737];
	// 	list.push_back(0); // [5, 3, 5, 737, 0];
	// 	std::list<int>::iterator it = list.begin();
	// 	std::list<int>::iterator ite = list.end();
	// 	++it;
	// 	--it;
	// 	while (it != ite)
	// 	{
	// 		std::cout << *it << std::endl;
	// 		++it;
	// 	}
	// }
	
	return 0;
}
