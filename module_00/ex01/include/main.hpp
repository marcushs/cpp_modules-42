/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:29:51 by hleung            #+#    #+#             */
/*   Updated: 2023/11/15 17:18:01 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTO_HPP
# define PROTO_HPP
# include <iostream> //std::cin std::cout std::endl
# include <string> //std::string std::getline
# include <cstdlib> //atoi
# include <iomanip> //std::setw std::setfill

# include "PhoneBook.hpp"
# include "Contact.hpp"

int		isValidPhone(std::string str);
int		hasNonPrintable(std::string str);

#endif
