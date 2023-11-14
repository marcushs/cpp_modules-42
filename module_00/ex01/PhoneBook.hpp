/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:32:08 by hleung            #+#    #+#             */
/*   Updated: 2023/11/14 14:43:18 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"

class   PhoneBook
{

public:
    
    PhoneBook(void);
    ~PhoneBook(void);
    void    addContact();
    void    searchContact();
    Contact    getContact(int i);
private:

    void    _printPhoneBook();
    Contact _contacts[8];
};

#endif
