/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 18:43:08 by hleung            #+#    #+#             */
/*   Updated: 2023/12/25 19:09:58 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"
#include <iostream>

/*------------------------------- Constructors -------------------------------*/

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &src) {*this = src;}

/*-------------------------------- Destructor --------------------------------*/

ScalarConverter::~ScalarConverter() {}

/*--------------------------------- Overload ---------------------------------*/

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &rhs) {static_cast<void>(rhs); return *this;}

/*----------------------------- Member Functions -----------------------------*/

void	ScalarConverter::convert(const std::string &s)
{
	std::cout << s << std::endl;
}
