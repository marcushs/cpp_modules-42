/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:45:24 by hleung            #+#    #+#             */
/*   Updated: 2023/11/16 13:59:00 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout << "The address of `str' is      : " << &str << std::endl;
	std::cout << "The address of `stringPTR' is: " << stringPTR << std::endl;
	std::cout << "The address of `stringREF' is: " << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "The value of `str' is        : " << str << std::endl;
	std::cout << "The value of `stringPTR' is  : " << *stringPTR << std::endl;
	std::cout << "The value of `stringREF' is  : " << stringREF << std::endl;
}
