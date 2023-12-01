/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:14:02 by hleung            #+#    #+#             */
/*   Updated: 2023/12/01 17:16:17 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

static void functionLoop(int i, void (Harl::*f[4])(void), Harl *harl);

Harl::Harl(void)
{
	return ;
}

Harl::~Harl(void)
{
	return ;
}

void	Harl::complain(std::string level)
{
	void	(Harl::*f[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int	i = 0;

	while (i < 4 && levels[i].compare(level))
		i++;
	switch (i)
	{
		case 0:
			functionLoop(i, f, this);
			break;

		case 1:
			functionLoop(i, f, this);
			break;

		case 2:
			functionLoop(i, f, this);
			break;

		case 3:
			functionLoop(i, f, this);
			break;
	
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}

void	Harl::debug(void)
{
	std::cout << "[DEBUG]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[INFO]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn\'t put enough bacon in my burger! If you did, I wouldn\'t be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[WARNING]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I\'ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ERROR]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

static void	functionLoop(int i, void (Harl::*f[4])(void), Harl *harl)
{
	for (; i < 4; i++)
		(harl->*f[i])();
}
