/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:05:15 by hleung            #+#    #+#             */
/*   Updated: 2024/01/04 19:54:47 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP
# include <stack>
# include <iterator>

template < typename T >
class MutantStack : public std::stack<T>
{

public:
	MutantStack() {}
	MutantStack(const MutantStack &src) {*this = src;}
	~MutantStack() {}

	MutantStack	&operator=(const MutantStack &rhs)
	{
		if (this != &rhs)
			this->c = rhs.c;
		return *this;
	}
	
	typedef typename std::stack<T>::container_type::iterator iterator;
	iterator	begin() {return this->c.begin();};
	iterator	end() {return this->c.end();};
};

#endif
