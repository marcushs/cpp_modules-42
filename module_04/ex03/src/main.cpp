/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:12:31 by hleung            #+#    #+#             */
/*   Updated: 2023/12/18 13:24:26 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AMateria.hpp"
#include "../include/Ice.hpp"
#include "../include/Cure.hpp"
#include "../include/ICharacter.hpp"
#include "../include/Character.hpp"
#include "../include/MateriaSource.hpp"
#include <iostream>

int	main(void)
{
	/*-----------Character test-----------*/
	// {
		// AMateria	*ice = new Ice();
		// AMateria	*ice2 = new Ice();
		// AMateria	*ice3 = new Ice();
		// AMateria	*ice4 = new Ice();
		// AMateria	*ice5 = new Ice();
		// AMateria	*cure = new Cure();
		// AMateria	*cure2 = new Cure();
		// AMateria	*cure3 = new Cure();
		// AMateria	*cure4 = new Cure();
		// AMateria	*cure5 = new Cure();
		// Character	*bob = new Character("bob");
		// Character	*max = new Character("max");

		// std::cout << ice->getType() << std::endl;
		// std::cout << cure->getType() << std::endl;
		// std::cout << std::endl;

		// std::cout << bob->getName() << std::endl;
		// std::cout << max->getName() << std::endl;
		// std::cout << std::endl;

		// bob->use(0, *max);
		// max->use(0, *bob);

		// bob->equip(ice);
		// bob->equip(ice2);
		// bob->equip(ice3);
		// bob->equip(ice4);
		// bob->equip(ice5);
		// max->equip(cure);
		// max->equip(cure2);
		// max->equip(cure3);
		// max->equip(cure4);
		// max->equip(cure5);

		// bob->use(0, *max);
		// bob->use(2, *max);
		// bob->use(4, *max);
		// max->use(0, *bob);
		// max->use(1, *bob);
		// max->use(3, *bob);

		// bob->unequip(0);
		// bob->unequip(2);
		// bob->unequip(3);

		
		// max->unequip(1);
		// max->unequip(0);
		// max->unequip(2);
		// max->unequip(3);
		// *max = *bob;
		// std::cout << bob->getName() << std::endl;
		// std::cout << max->getName() << std::endl;

		// bob->use(0, *max);
		// max->use(0, *bob);
		// bob->use(1, *max);
		// max->use(1, *bob);
		// bob->use(2, *max);
		// max->use(2, *bob);


		// delete ice;
		// delete ice2;
		// delete ice3;
		// delete ice4;
		// delete ice5;
		// delete cure;
		// delete cure2;
		// delete cure3;
		// delete cure4;
		// delete cure5;
		// delete bob;
		// delete max;
	// }
	
	/*-----------AMateria test-----------*/
	// {
	// 	AMateria	*ice = new Ice();
	// 	AMateria	*cure = new Cure();
	// 	AMateria	*ice2 = ice->clone();
	// 	AMateria	*cure2 = cure->clone();

	// 	std::cout << ice2->getType() << std::endl;
	// 	std::cout << cure2->getType() << std::endl;
	// 	std::cout << std::endl;

	// 	*ice = *cure2;
	// 	*cure = *ice2;
		
	// 	std::cout << ice->getType() << std::endl;
	// 	std::cout << cure->getType() << std::endl;
	// 	std::cout << ice2->getType() << std::endl;
	// 	std::cout << cure2->getType() << std::endl;
	// 	std::cout << std::endl;
		
	// 	delete ice;
	// 	delete ice2;
	// 	delete cure;
	// 	delete cure2;
	// }

	/*-----------MateriaSource test-----------*/
	{
		IMateriaSource* src = new MateriaSource();

		Ice	*ice = new Ice();
		src->learnMateria(ice);
		src->learnMateria(ice);
		for (int i = 0; i < 3; i++)
		{
			src->learnMateria(new Ice());
			src->learnMateria(new Cure());
		}
		ICharacter* me = new Character("me");
		MateriaSource* src2 = new MateriaSource(*(MateriaSource *)src);
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		tmp = src2->createMateria("cure");
		me->equip(tmp);
		tmp = src2->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("fire");
		me->unequip(3);
		ICharacter* bob = new Character("bob");
		ICharacter* max = new Character(*(Character *)bob);
		me->use(0, *bob);
		me->use(1, *max);
		max->use(1, *me);
		*(Character *)max = *(Character *)me;
		max->use(1, *me);
		max->unequip(0);
		max->use(0, *bob);
		delete bob;
		delete max;
		delete me;
		delete src;
		delete src2;
		return 0;
	}

}
