/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:32:08 by hleung            #+#    #+#             */
/*   Updated: 2023/11/14 12:20:08 by hleung           ###   ########.fr       */
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
    Contact    getContact(int i);
private:

    Contact _contacts[8];
};

#endif
