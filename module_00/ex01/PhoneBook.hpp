/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:32:08 by hleung            #+#    #+#             */
/*   Updated: 2023/11/15 14:31:27 by hleung           ###   ########.fr       */
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

    void    _printPhoneBook(void);
    void    _printPhoneBookShort(std::string str);
    void    _printContactDetail(int idx);
    Contact _contacts[8];
};

#endif
