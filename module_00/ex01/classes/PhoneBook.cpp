/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:56:19 by hleung            #+#    #+#             */
/*   Updated: 2023/11/15 17:16:15 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.hpp"
#include "../include/PhoneBook.hpp"
#include "../include/Contact.hpp"

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

	this->_addPrompt(strs);
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
	int			nbContact = Contact::getNbContact();

	this->_printPhoneBook();
	if (nbContact > 0)
		this->_searchContactPrompt(nbContact);
	else
		std::cout << "No entry" << std::endl;
}

Contact	PhoneBook::getContact(int i)
{
	return this->_contacts[i];
}

void	PhoneBook::_addPrompt(std::string strs[5])
{
	for (int i = 0; i < 5; i++)
	{
		do
		{
			if (i == 0)
				std::cout << ">> Enter First Name    :";
			else if (i == 1)
				std::cout << ">> Enter Last Name     :";
			else if (i == 2)
				std::cout << ">> Enter Nick Name     :";
			else if (i == 3)
				std::cout << ">> Enter Phone Number  :";
			else if (i == 4)
				std::cout << ">> Enter Darket Secret :";
			std::getline(std::cin, strs[i]);
			if (std::cin.eof())
				exit(EXIT_FAILURE);
			if (hasNonPrintable(strs[i]))
			{
				std::cout << "Non printable characters are not accepted" << std::endl;
				strs[i].clear();
			}
			if (i == 3 && !isValidPhone(strs[3]))
				strs[3].clear();
		} while (strs[i].empty());
	}
}

void	PhoneBook::_printPhoneBook()
{
	int	nbContact = (Contact::getNbContact() >= 8) ? 8 : Contact::getNbContact();
	
	this->_printPhoneBookHeader();
	for (int i = 0; i < nbContact; i++)
	{
		std::cout << "*" << std::setfill(' ') << std::setw(10) << i << "|";
		this->_printPhoneBookShort(this->_contacts[i].getFirstName());
		std::cout << "|";
		this->_printPhoneBookShort(this->_contacts[i].getLastName());
		std::cout << "|";
		this->_printPhoneBookShort(this->_contacts[i].getNickName());
		std::cout << "*";
		std::cout << std::endl;
	}
	std::cout << std::setfill('*') << std::setw(45);
	std::cout << "*" << std::endl;
	std::cout << std::endl;
}

void	PhoneBook::_printPhoneBookHeader(void)
{
	std::cout << std::endl;
	std::cout << std::setfill('*') << std::setw(45);
	std::cout << "*" << std::endl;
	std::cout << "*   INDEX  ";
	std::cout << "|";
	std::cout << "  F.NAME  ";
	std::cout << "|";
	std::cout << "  L.NAME  ";
	std::cout << "|";
	std::cout << "  N.NAME  ";
	std::cout << "*";
	std::cout << std::endl;
	std::cout << "*";
	std::cout << std::setfill('-') << std::setw(44);
	std::cout << "*";
	std::cout << std::endl;
}

void	PhoneBook::_printPhoneBookShort(std::string str)
{
	int	len = str.length();
	
	if (len >= 10)
	{
		for(int i = 0; i < 9; i++)
			std::cout << str[i];
		std::cout << ".";
	}
	else
		std::cout << std::setfill(' ') << std::setw(10) << str;
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

void	PhoneBook::_searchContactPrompt(int nbContact)
{
	std::string	input;
	int			idx = -1;

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
