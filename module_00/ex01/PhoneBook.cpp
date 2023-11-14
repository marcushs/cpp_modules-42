/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:56:19 by hleung            #+#    #+#             */
/*   Updated: 2023/11/14 16:04:27 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto.hpp"
#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook(void)
{
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

void	PhoneBook::addContact(void)
{
	std::string	strs[5];
	int			nbContact = Contact::getNbContact();
	int			idx = (nbContact == 0) ? 0 : nbContact % 8;

	addPrompt(strs);
	strs[0] = strs[0].substr(strs[0].find_first_not_of(" 	"), strs[0].find_last_not_of(" 	"));
	this->_contacts[idx].setFirstName(strs[0]);
	this->_contacts[idx].setLastName(strs[1]);
	this->_contacts[idx].setNickName(strs[2]);
	this->_contacts[idx].setPhoneNumber(strs[3]);
	this->_contacts[idx].setSecret(strs[4]);
	std::cout << "Contact successfully added to phone book!" << std::endl;
	Contact::incrementNbContact();
}

void	PhoneBook::searchContact()
{
	std::string	input;
	int			nbContact = Contact::getNbContact();

	this->_printPhoneBook();
	if (nbContact > 0)
	{
		while (1)
		{
			std::cout << "Enter index of contact to see detail: ";
			std::getline(std::cin, input);
			
		}
	}
}

void	PhoneBook::_printPhoneBook()
{
	int	nbContact = Contact::getNbContact();
	int	idx = (nbContact == 0) ? 0 : nbContact % 8;
	
	printPhoneBookHeader();
	for (int i = 0; i < idx; i++)
	{
		printChars(1, "*");
		printChars(9, " ");
		std::cout << i << "|";
		printPhoneBookShort(this->_contacts[i].getFirstName());
		std::cout << "|";
		printPhoneBookShort(this->_contacts[i].getLastName());
		std::cout << "|";
		printPhoneBookShort(this->_contacts[i].getNickName());
		std::cout << "*";
		std::cout << std::endl;
	}
	printChars(45, "*");
	std::cout << std::endl;
}

Contact	PhoneBook::getContact(int i)
{
	return this->_contacts[i];
}

