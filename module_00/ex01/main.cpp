/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 08:26:45 by hleung            #+#    #+#             */
/*   Updated: 2023/11/14 15:23:58 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto.hpp"
#include "PhoneBook.hpp"
#include "Contact.hpp"

void	prompt_cmd(PhoneBook *pb);
// static int	is_cmd(PhoneBook *pb, std::string cmd);

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
