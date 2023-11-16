/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:32:08 by hleung            #+#    #+#             */
/*   Updated: 2023/11/16 09:15:27 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include <string>
# include "Contact.hpp"

class   PhoneBook
{

public:

    PhoneBook(void);
    ~PhoneBook(void);
    void    addContact(void);
    void    searchContact(void);
    Contact    getContact(int i);
private:

    void	_addPrompt(std::string strs[5]);
    void    _printPhoneBook(void);
    void	_printPhoneBookHeader(void);
    void    _printPhoneBookShort(std::string str);
    void    _printContactDetail(int idx);
    void    _searchContactPrompt(int nbContact);
    Contact _contacts[8];
};

#endif
