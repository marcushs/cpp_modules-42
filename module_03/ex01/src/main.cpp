/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 09:43:19 by hleung            #+#    #+#             */
/*   Updated: 2023/12/11 20:10:49 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScavTrap.hpp"

int main(void)
{
	ScavTrap bob("bob");
	ScavTrap max("max");
	ScavTrap a(bob);

	std::cout << bob << std::endl;
	std::cout << max << std::endl;
	std::cout << a << std::endl;

	bob.guardGate();
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
