/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:17:46 by hleung            #+#    #+#             */
/*   Updated: 2024/05/03 08:14:22 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP
# include <stack>
# include <iostream>
# include <cstdlib>
# include <list>

class RPN
{
public:
	RPN();
	~RPN();
	void	calculate(std::string exp);
	void	manipStack(const std::string &token);
	void	doOps(int x, int y, const std::string &op);
	
private:
	RPN(const RPN &src);
	RPN	&operator=(const RPN &rhs);
	std::stack<int, std::list<int> >	_stack;
};

#endif
