/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:56:19 by hleung            #+#    #+#             */
/*   Updated: 2023/11/15 15:03:05 by hleung           ###   ########.fr       */
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
	int			idx = -1;

	this->_printPhoneBook();
	if (nbContact > 0)
	{
		while (1)
		{
			std::cout << "Enter index of contact to see detail: ";
			std::getline(std::cin, input);
			if (std::cin.eof())
				exit(EXIT_FAILURE);
			if (input.length() == 1 && isdigit(input[0]))
			{
				idx = atoi(input.c_str());
				if (idx < 0 || idx > 7)
				{
					std::cout << "Please enter a value between 0 to 7 inclusive" << std::endl;
					continue ;
				}
				else if (idx >= nbContact)
					std::cout << "Index has no contact entry" << std::endl;
				else
				{
					this->_printContactDetail(idx);
					break ;
				}
			}
			else 
				std::cout << "Please enter a value between 0 to 7 inclusive" << std::endl;
		}
	}
}

void	PhoneBook::_printContactDetail(int idx)
{
	std::cout << std::endl;
	std::cout << "First Name     :" << this->_contacts[idx].getFirstName() << std::endl;
	std::cout << "Last Name      :" << this->_contacts[idx].getLastName() << std::endl;
	std::cout << "Nick Name      :" << this->_contacts[idx].getNickName() << std::endl;
	std::cout << "Phone Number   :" << this->_contacts[idx].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret :" << this->_contacts[idx].getSecret() << std::endl;
}

void	PhoneBook::_printPhoneBook()
{
	int	nbContact = (Contact::getNbContact() >= 8) ? 8 : Contact::getNbContact();
	
	printPhoneBookHeader();
	for (int i = 0; i < nbContact; i++)
	{
		printChars(1, "*");
		printChars(9, " ");
		std::cout << i << "|";
		this->_printPhoneBookShort(this->_contacts[i].getFirstName());
		std::cout << "|";
		this->_printPhoneBookShort(this->_contacts[i].getLastName());
		std::cout << "|";
		this->_printPhoneBookShort(this->_contacts[i].getNickName());
		std::cout << "*";
		std::cout << std::endl;
	}
	printChars(45, "*");
	std::cout << std::endl;
}

void	PhoneBook::_printPhoneBookShort(std::string str)
{
	std::string	tmp = str.substr(str.find_first_not_of(" 	"), str.find_last_not_of(" 	") + 1);
	int			len = tmp.length();
	
	if (len >= 10)
	{
		for(int i = 0; i < 9; i++)
			std::cout << tmp[i];
		std::cout << ".";
	}
	else
	{
		printChars(10 - len, " ");
		std::cout << tmp;
	}
}

Contact	PhoneBook::getContact(int i)
{
	return this->_contacts[i];
}

