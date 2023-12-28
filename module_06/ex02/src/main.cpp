/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 09:22:36 by hleung            #+#    #+#             */
/*   Updated: 2023/12/28 10:22:22 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/helpers.hpp"
#include <unistd.h>

int	main(void)
{
	Base	*base;
	unsigned int	times = 5;

	for(unsigned int i = 0; i < times; i++)
	{
		base = generate();
		
		std::cout << "Calling identify(Base *p)" << std::endl;
		identify(base);
		std::cout << "Calling identify(Base &p)" << std::endl;
		identify(*base);

		delete base;
		sleep(1);
	}
}
