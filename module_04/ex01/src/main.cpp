/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 07:31:23 by hleung            #+#    #+#             */
/*   Updated: 2023/12/14 10:01:52 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"
#include "../include/Dog.hpp"
#include "../include/Cat.hpp"
#include "../include/WrongAnimal.hpp"
#include "../include/WrongCat.hpp"
#include <iostream>

int	main(void)
{
	// {	
	// 	Animal	*animalFarm[10];
		
	// 	for (int i = 0; i < 10; i++)
	// 		(i % 2 == 0) ? animalFarm[i] = new Cat() : animalFarm[i] = new Dog();

	// 	for (int i = 0; i < 10; i++)
	// 		animalFarm[i]->makeSound();

	// 	for (int i = 0; i < 10; i++)
	// 		delete animalFarm[i];
	// }

	// std::cout << "---------------------------" << std::endl;
	
	// {
	// 	Animal	*a = new Dog();

	// 	std::cout << std::endl;
		
	// 	a->makeSound();
	// 	a->getBrain()->setIdea(10, "idea: eat bone in 3 minutes");
	// 	std::cout << a->getBrain()->getIdea(10) << std::endl;

	// 	std::cout << std::endl;
		
	// 	Animal	*b = new Dog(*a);
		
	// 	std::cout << std::endl;
		
	// 	std::cout << b->getBrain()->getIdea(10) << std::endl;
	// 	b->getBrain()->setIdea(0, "idea: index 0");
	// 	std::cout << b->getBrain()->getIdea(0) << std::endl;
	// 	std::cout << a->getBrain()->getIdea(0) << std::endl;
		
	// 	delete a;
	// 	delete b;
	// }
	
	// std::cout << "---------------------------" << std::endl;
	
	// {
	// 	Animal	*a = new Cat();

	// 	std::cout << std::endl;

	// 	a->makeSound();
	// 	a->getBrain()->setIdea(10, "idea: eat fish NOW!");
	// 	std::cout << a->getBrain()->getIdea(10) << std::endl;

	// 	std::cout << std::endl;
		
	// 	Animal	*b = new Cat(*a);
		
	// 	std::cout << std::endl;
		
	// 	std::cout << b->getBrain()->getIdea(10) << std::endl;

	// 	std::cout << std::endl;
		
	// 	b->getBrain()->setIdea(0, "idea: index 0");
	// 	std::cout << b->getBrain()->getIdea(0) << std::endl;
	// 	std::cout << a->getBrain()->getIdea(0) << std::endl;
				
	// 	delete a;
	// 	delete b;
	// }
	
	{
		Dog	*dog = new Dog();
		Dog	*dog2 = new Dog();
		Cat *cat1 = new Cat();
		
		std::cout << std::endl;

		dog->getBrain()->setIdea(10, "dog index 10");
		dog2->getBrain()->setIdea(10, "dog2 index 10");
		cat1->getBrain()->setIdea(10, "cat1 index 10");

		std::cout << dog->getBrain()->getIdea(10) << std::endl;
		std::cout << dog2->getBrain()->getIdea(10) << std::endl;
		std::cout << cat1->getBrain()->getIdea(10) << std::endl;

		std::cout << std::endl;

		*dog = *dog2;
		*dog2 = *cat1;

		std::cout << std::endl;
		
		std::cout << dog->getBrain()->getIdea(10) << std::endl;
		std::cout << dog2->getBrain()->getIdea(10) << std::endl;
		std::cout << cat1->getBrain()->getIdea(10) << std::endl;

		std::cout << std::endl;
		
		dog->getBrain()->setIdea(11, "dog index 11");
		dog2->getBrain()->setIdea(11, "dog2 index 11");
		cat1->getBrain()->setIdea(11, "cat1 index 11");
		
		std::cout << dog->getBrain()->getIdea(10) << std::endl;
		std::cout << dog->getBrain()->getIdea(11) << std::endl;
		std::cout << std::endl;
		std::cout << dog2->getBrain()->getIdea(10) << std::endl;
		std::cout << dog2->getBrain()->getIdea(11) << std::endl;
		std::cout << std::endl;
		std::cout << cat1->getBrain()->getIdea(10) << std::endl;
		std::cout << cat1->getBrain()->getIdea(11) << std::endl;
		
		std::cout << std::endl;
		
		delete dog;
		delete dog2;
		delete cat1;
	}

	{
		Dog basic;
		
		std::cout << std::endl;
		basic.getBrain()->setIdea(0, "IDEA");
		std::cout << basic.getBrain()->getIdea(0) << std::endl;
		
		Dog tmp = basic;
		
		std::cout << std::endl;
		std::cout << tmp.getBrain()->getIdea(0) << std::endl;
		std::cout << std::endl;
		tmp.getBrain()->setIdea(0, "HELLO");
		std::cout << tmp.getBrain()->getIdea(0) << std::endl;
		std::cout << basic.getBrain()->getIdea(0) << std::endl;
		
	}

}
