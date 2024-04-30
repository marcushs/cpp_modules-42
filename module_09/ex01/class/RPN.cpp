/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:17:17 by hleung            #+#    #+#             */
/*   Updated: 2024/04/30 20:06:36 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RPN.hpp"

static void	isValidToken(const std::string &token);
static bool	isOperator(const std::string &token);

/*------------------------------- Constructors -------------------------------*/

RPN::RPN() {}

RPN::RPN(const RPN &src) {*this = src;}

/*-------------------------------- Destructor --------------------------------*/

RPN::~RPN() {}

/*--------------------------------- Overload ---------------------------------*/

RPN	&RPN::operator=(const RPN &rhs)
{
	if (this != &rhs)
		this->_stack = rhs._stack;
	return (*this);
}

/*----------------------------- Member Functions -----------------------------*/

// In the below function, use istringstream (>> operator) to parse the input string can avoid needing to remove whitespace manually
void	RPN::calculate(std::string exp)
{
	if (exp.empty() || exp.find_first_not_of(" \t\n\v\r0123456789+-*/") != exp.npos)
		throw std::runtime_error("Error");
	while (true) {
		size_t	head = exp.find_first_not_of(" \t\n\v\r");
		if (head == exp.npos) {
			if (this->_stack.size() != 1)
				throw std::runtime_error("Error");
			std::cout << this->_stack.top() << std::endl;
			return ;
		}
		exp = exp.substr(head);
		size_t	end = exp.find_first_of(" \t\n\v\r");
		std::string	tmp = exp.substr(0, end);
		isValidToken(tmp);
		manipStack(tmp);
		if (end == exp.npos)
		{
			if (this->_stack.size() != 1)
				throw std::runtime_error("Error");
			std::cout << this->_stack.top() << std::endl;
			return ;
		}
		exp = exp.substr(end);
	}
}

void	RPN::manipStack(const std::string &token)
{
	if (!isOperator(token)) {
		int	operand = atoi(token.c_str());
		if (operand < -9 || operand > 9)
			throw std::runtime_error("Error");
		this->_stack.push(operand);
	} else {
		if (this->_stack.size() < 2)
			throw std::runtime_error("Error");
		int operand1, operand2;
		operand1 = this->_stack.top();
		this->_stack.pop();
		operand2 = this->_stack.top();
		this->_stack.pop();
		doOps(operand1, operand2, token);
	}
}

void	RPN::doOps(int x, int y, const std::string &op)
{
	if (op == "+") {
		this->_stack.push(y + x);
		return;
	}
	if (op == "-") {
		this->_stack.push(y - x);
		return;
	}
	if (op == "*") {
		this->_stack.push(y * x);
		return;
	}
	if (op == "/") {
		if (x == 0)
			throw std::runtime_error("Error");
		this->_stack.push(y / x);
		return;
	}
}

/*------------------------- Static Helper Functions --------------------------*/

static void	isValidToken(const std::string &token)
{
	if (token.length() > 2)
		throw std::runtime_error("Error");
	if (token.length() == 2) {
		if (token[0] == '*' || token[0] == '/')
			throw std::runtime_error("Error");
		if (token[0] == '-' && !isdigit(token[1]))
			throw std::runtime_error("Error");
		if (!isdigit(token[1]))
			throw std::runtime_error("Error");
	}
}

static bool	isOperator(const std::string &token)
{
	return (token.length() == 1 && token.find_first_of("+-*/") != token.npos);
}
