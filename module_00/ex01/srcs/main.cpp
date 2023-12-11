/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 08:26:45 by hleung            #+#    #+#             */
/*   Updated: 2023/12/11 09:23:44 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.hpp"
#include "../include/PhoneBook.hpp"
#include "../include/Contact.hpp"

static void	prompt_cmd(PhoneBook *pb);
static void	greet(void);

int	main(int argc, char **argv)
{
	(void)argv;
	PhoneBook	pb;

	if (argc == 1)
		prompt_cmd(&pb);
	else
		std::cout << "Program does not take argument" << std::endl;
}

static void	prompt_cmd(PhoneBook *pb)
{
	std::string	cmd;

	while (1)
	{
		greet();
		std::getline(std::cin, cmd);
		if (!cmd.compare("ADD"))
			pb->addContact();
		else if(!cmd.compare("SEARCH"))
			pb->searchContact();
		else if (!cmd.compare("EXIT") || std::cin.eof())
			return ;
		else
			std::cout << "Invalid command, input is case-sensitive" << std::endl;
	}
	return ;
}

static void	greet(void)
{
	std::cout << std::endl;
	std::cout << std::setfill('*') << std::setw(47);
	std::cout << "*" << std::endl;
	std::cout << "*";
	std::cout << std::setfill(' ') << std::setw(7);
	std::cout << " " << "Welcome to My Awesome Phonebook!";
	std::cout << std::setfill(' ') << std::setw(7) << "*";
	std::cout << std::endl;
	std::cout << "* Please enter a command (ADD, SEARCH, EXIT)! *";
	std::cout << std::endl;
	std::cout << std::setfill('*') << std::setw(47);
	std::cout << "*" << std::endl;
	std::cout << std::endl;
}
