/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 07:31:23 by hleung            #+#    #+#             */
/*   Updated: 2023/12/13 08:25:44 by hleung           ###   ########.fr       */
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
	const Animal* a = new Animal();
	const Animal* cat = new Cat();
	const Animal* dog = new Dog();
	
	std::cout << a->getType() << " " << std::endl; // Output: Generic animal
	std::cout << cat->getType() << " " << std::endl; // Output: Cat
	std::cout << dog->getType() << " " << std::endl; // Output: Dog
	
	a->makeSound(); // Output: "Generic animal goes "RANDON ANIMAL SOUND""
	cat->makeSound(); // Output: "Cat goes "MEOW MEOW""
	dog->makeSound(); // Output: "Dog does "ROOF ROOF""

	delete a;
	delete cat;
	delete dog;

	const WrongAnimal* b = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();

	std::cout << b->getType() << " " << std::endl; // Output: "Generic WrongAnimal"
	std::cout << wrongCat->getType() << " " << std::endl; // Output: "WrongCat"
	
	b->makeSound(); // Output: "Generic WrongAnimal goes "RANDOM WRONG_ANIMAL SOUND""
	wrongCat->makeSound(); // Output: "WrongCat goes "RANDOM WRONG_ANIMAL SOUND""

	delete b;
	delete wrongCat;
	
	return 0;
}
