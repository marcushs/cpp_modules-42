/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:29:51 by hleung            #+#    #+#             */
/*   Updated: 2023/11/14 10:37:43 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTO_HPP
# define PROTO_HPP
# include <iostream>
# include <string>
# include "PhoneBook.hpp"
# include "Contact.hpp"

void	greet(void);
void	printChars(int s, std::string c);
void	addContact(PhoneBook *pb);
void	addPrompt(std::string strs[5]);

#endif
