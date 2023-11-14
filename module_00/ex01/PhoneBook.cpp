/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:56:19 by hleung            #+#    #+#             */
/*   Updated: 2023/11/14 12:19:56 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto.hpp"
#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook(void)
{
	std::cout << "Phonebook Constructor called\n";
	return ;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "Phonebook Destructor called\n";
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
	Contact::incrementNbContact();
}

Contact	PhoneBook::getContact(int i)
{
	return this->_contacts[i];
}

