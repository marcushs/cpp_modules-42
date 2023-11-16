/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:58:55 by hleung            #+#    #+#             */
/*   Updated: 2023/11/16 07:30:42 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.hpp"
#include "../include/PhoneBook.hpp"
#include "../include/Contact.hpp"

Contact::Contact(void)
{
	
	return ;
}

Contact::~Contact(void)
{
	return ;
}

int	Contact::getNbContact(void)
{
	return Contact::_nbContact;
}

void	Contact::incrementNbContact(void)
{
	Contact::_nbContact++;
	return ;
}

std::string	Contact::getFirstName(void) const
{
	return this->_firstName;	
}

std::string	Contact::getLastName(void) const
{
	return this->_lastName;
}

std::string	Contact::getNickName(void) const
{
	return this->_nickName;
}

std::string	Contact::getPhoneNumber(void) const
{
	return this->_phoneNumber;
}

std::string	Contact::getSecret(void) const
{
	return this->_secret;
}

void	Contact::setFirstName(std::string fn)
{
	this->_firstName = fn;
}

void	Contact::setLastName(std::string ln)
{
	this->_lastName = ln;
}

void	Contact::setNickName(std::string nn)
{
	this->_nickName = nn;
}

void	Contact::setPhoneNumber(std::string pn)
{
	this->_phoneNumber = pn;
}

void	Contact::setSecret(std::string sec)
{
	this->_secret = sec;
}

int	Contact::_nbContact = 0;
