/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 07:31:23 by hleung            #+#    #+#             */
/*   Updated: 2023/12/13 16:31:42 by hleung           ###   ########.fr       */
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
	// 	Animal	*a = new Animal();
		
	// 	delete a;
	// }
	
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
	// 	Dog	*a = new Dog();
	// 	a->makeSound();
	// 	a->getBrain()->setIdea(10, "idea: eat bone in 3 minutes");
	// 	std::cout << a->getBrain()->getIdea(10) << std::endl;
	// 	Dog	*b = new Dog(*a);
		
	// 	std::cout << b->getBrain()->getIdea(10) << std::endl;
	// 	b->getBrain()->setIdea(0, "idea: index 0");
	// 	std::cout << b->getBrain()->getIdea(0) << std::endl;
	// 	std::cout << a->getBrain()->getIdea(0) << std::endl;
		
	// 	delete a;
	// 	delete b;
	// }
	
	// std::cout << "---------------------------" << std::endl;
	
	// {
	// 	Cat	*a = new Cat();
	// 	a->makeSound();
	// 	a->getBrain()->setIdea(10, "idea: eat fish NOW!");
	// 	std::cout << a->getBrain()->getIdea(10) << std::endl;
	// 	Cat	*b = new Cat(*a);
		
	// 	std::cout << b->getBrain()->getIdea(10) << std::endl;
	// 	b->getBrain()->setIdea(0, "idea: index 0");
	// 	std::cout << b->getBrain()->getIdea(0) << std::endl;
	// 	std::cout << a->getBrain()->getIdea(0) << std::endl;
		
	// 	delete a;
	// 	delete b;
	// }

	{
		Dog	*dog = new Dog();
		Dog	*dog2 = new Dog();

		dog->getBrain()->setIdea(10, "dog index 10");
		dog2->getBrain()->setIdea(10, "dog2 index 10");

		std::cout << dog->getBrain()->getIdea(10) << std::endl;
		std::cout << dog2->getBrain()->getIdea(10) << std::endl;
	}
}
