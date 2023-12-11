/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 09:43:19 by hleung            #+#    #+#             */
/*   Updated: 2023/12/11 11:24:48 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap bob("bob");
	ClapTrap max("max");
	
	std::cout << bob << std::endl;
	std::cout << max << std::endl;
	bob.attack(max.getName());
	std::cout << bob << std::endl;
	max.takeDamage(3);
	std::cout << max << std::endl;
	max.beRepaired(7);
	std::cout << max << std::endl;
	for (int i = 0; i < 10; i++)
		bob.attack(max.getName());
	max.takeDamage(100);
	std::cout << max << std::endl;
	max.attack(bob.getName());
	std::cout << bob << std::endl;
}
