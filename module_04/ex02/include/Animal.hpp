/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 07:01:21 by hleung            #+#    #+#             */
/*   Updated: 2023/12/14 10:03:31 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <string>
# include "Brain.hpp"

class Animal
{

public:
	Animal(void);
	Animal(const Animal &src);
	virtual ~Animal(void);
	
	virtual Animal	&operator=(const Animal &rhs);
	std::string getType(void) const;

	virtual void	makeSound(void) const = 0;
	virtual Brain	*getBrain(void) const;
	
protected:
	std::string	_type;
	
};




#endif
