/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:17:46 by hleung            #+#    #+#             */
/*   Updated: 2024/04/30 19:40:56 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP
# include <stack>
# include <iostream>
# include <cstdlib>

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
	std::stack<int>	_stack;
};

#endif
