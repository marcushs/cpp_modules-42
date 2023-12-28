/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 09:28:31 by hleung            #+#    #+#             */
/*   Updated: 2023/12/28 10:14:31 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/helpers.hpp"

static Base	*generateA(void);
static Base	*generateB(void);
static Base	*generateC(void);

Base	*generate(void)
{
	Base	*(*f[3])(void) = {generateA, generateB, generateC};

	srand(static_cast<unsigned int>(time(NULL)));
	return (f[rand() % 3]());
}

void	identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "The pointer is of class A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "The pointer is of class B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "The pointer is of class C" << std::endl;
}

void	identify(Base &p)
{
	if (dynamic_cast<A *>(&p))
		std::cout << "The pointer is of class A" << std::endl;
	else if (dynamic_cast<B *>(&p))
		std::cout << "The pointer is of class B" << std::endl;
	else if (dynamic_cast<C *>(&p))
		std::cout << "The pointer is of class C" << std::endl;
}

static Base	*generateA(void) {return new A;}
static Base	*generateB(void) {return new B;}
static Base	*generateC(void) {return new C;}
