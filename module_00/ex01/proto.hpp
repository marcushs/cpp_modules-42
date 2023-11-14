/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:29:51 by hleung            #+#    #+#             */
/*   Updated: 2023/11/14 15:32:04 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTO_HPP
# define PROTO_HPP
# include <iostream>
# include <string>
# include <cstdlib>

# include "PhoneBook.hpp"
# include "Contact.hpp"

void	greet(void);
void	printChars(int s, std::string c);
void	addPrompt(std::string strs[5]);
void	printPhoneBookHeader(void);
void	printPhoneBookShort(std::string str);

#endif
