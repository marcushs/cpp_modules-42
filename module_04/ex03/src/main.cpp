/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:12:31 by hleung            #+#    #+#             */
/*   Updated: 2023/12/17 19:45:05 by hleung           ###   ########.fr       */
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
	AMateria	*ice2 = new Ice();
	AMateria	*ice3 = new Ice();
	AMateria	*ice4 = new Ice();
	AMateria	*ice5 = new Ice();
	AMateria	*cure = new Cure();
	AMateria	*cure2 = new Cure();
	AMateria	*cure3 = new Cure();
	AMateria	*cure4 = new Cure();
	AMateria	*cure5 = new Cure();
	Character	*bob = new Character("bob");
	Character	*max = new Character("max");

	std::cout << ice->getType() << std::endl;
	std::cout << cure->getType() << std::endl;
	std::cout << std::endl;

	std::cout << bob->getName() << std::endl;
	std::cout << max->getName() << std::endl;
	std::cout << std::endl;

	bob->use(0, *max);
	max->use(0, *bob);

	bob->equip(ice);
	bob->equip(ice2);
	bob->equip(ice3);
	bob->equip(ice4);
	bob->equip(ice5);
	max->equip(cure);
	max->equip(cure2);
	max->equip(cure3);
	max->equip(cure4);
	max->equip(cure5);

	// bob->use(0, *max);
	// bob->use(2, *max);
	// bob->use(4, *max);
	// max->use(0, *bob);
	// max->use(1, *bob);
	// max->use(3, *bob);

	bob->unequip(0);
	bob->unequip(2);
	bob->unequip(3);

	
	// max->unequip(1);
	max->unequip(0);
	// max->unequip(2);
	// max->unequip(3);
	*max = *bob;
	std::cout << bob->getName() << std::endl;
	std::cout << max->getName() << std::endl;

	bob->use(0, *max);
	max->use(0, *bob);
	bob->use(1, *max);
	max->use(1, *bob);
	bob->use(2, *max);
	max->use(2, *bob);


	delete ice;
	delete ice2;
	delete ice3;
	delete ice4;
	delete ice5;
	delete cure;
	delete cure2;
	delete cure3;
	delete cure4;
	delete cure5;
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
