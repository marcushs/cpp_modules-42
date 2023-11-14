/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 08:26:45 by hleung            #+#    #+#             */
/*   Updated: 2023/11/14 12:28:11 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto.hpp"
#include "PhoneBook.hpp"
#include "Contact.hpp"

void	prompt_cmd(PhoneBook *pb);
static int	is_cmd(PhoneBook *pb, std::string cmd);

int	main(void)
{
	PhoneBook	pb;
	
	prompt_cmd(&pb);
	// std::cout << input << std::endl;
	// pb.addContact();
	// pb.addContact();
	// std::cout << pb.getContact(0).getFirstName() << std::endl;
	// std::cout << pb.getContact(1).getFirstName() << std::endl;
}

void	prompt_cmd(PhoneBook *pb)
{
	std::string	cmd;

	do
	{
		greet();
		std::getline(std::cin, cmd);
	} while (!is_cmd(pb, cmd));
	return ;
}

static int	is_cmd(PhoneBook *pb, std::string cmd)
{
	if (cmd.compare("ADD") == 0)
	{
		pb->addContact();
		return (1);
	}
	else if (cmd.compare("SEARCH") == 0)
		return (1);
	else if (cmd.compare("EXIT") == 0)
		return (1);
	std::cout << "Invalid command, input is case-sensitive" << std::endl;
	return (0);
}
