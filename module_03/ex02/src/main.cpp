/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 09:43:19 by hleung            #+#    #+#             */
/*   Updated: 2023/12/13 14:10:17 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/FragTrap.hpp"

int main(void)
{
	FragTrap bob("bob");
	FragTrap max("max");
	FragTrap a(max);

	std::cout << bob << std::endl;
	std::cout << max << std::endl;
	std::cout << a << std::endl;

	bob.attack(a.getName());
	std::cout << bob << std::endl;

	a.takeDamage(3);
	std::cout << a << std::endl;

	max.beRepaired(7);
	std::cout << max << std::endl;

	for (int i = 0; i < 10; i++)
		bob.attack(max.getName());
	std::cout << bob << std::endl;

	max.takeDamage(200);
	std::cout << max << std::endl;

	bob.beRepaired(200);
	std::cout << bob << std::endl;

	max.attack(bob.getName());
	std::cout << bob << std::endl;
	bob.highFiveGuys();
	max.highFiveGuys();
}
