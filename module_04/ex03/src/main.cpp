/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:12:31 by hleung            #+#    #+#             */
/*   Updated: 2023/12/16 16:46:26 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AMateria.hpp"
#include "../include/Ice.hpp"
#include "../include/Cure.hpp"
#include "../include/ICharacter.hpp"
#include "../include/Character.hpp"
#include <iostream>

int	main(void)
{
	AMateria	*ice = new Ice();
	AMateria	*cure = new Cure();
	ICharacter	*bob = new Character("bob");
	ICharacter	*max = new Character("max");

	std::cout << ice->getType() << std::endl;
	std::cout << cure->getType() << std::endl;
	std::cout << std::endl;

	std::cout << bob->getName() << std::endl;
	std::cout << max->getName() << std::endl;
	std::cout << std::endl;

	bob->use(0, *max);
	max->use(0, *bob);

	bob->equip(ice);
	max->equip(cure);

	bob->use(0, *max);
	max->use(0, *bob);
	delete ice;
	delete cure;
	delete bob;
	delete max;

	// AMateria	*ice2 = ice->clone();
	// AMateria	*cure2 = cure->clone();

	// std::cout << ice2->getType() << std::endl;
	// std::cout << cure2->getType() << std::endl;
	// std::cout << std::endl;

	// ice = cure2;
	// cure = ice2;
	
	// std::cout << ice->getType() << std::endl;
	// std::cout << cure->getType() << std::endl;
	// std::cout << ice2->getType() << std::endl;
	// std::cout << cure2->getType() << std::endl;
	// std::cout << std::endl;
	
	// delete ice;
	// delete ice2;
	// delete cure;
	// delete cure2;


}
