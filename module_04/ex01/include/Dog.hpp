/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 07:09:49 by hleung            #+#    #+#             */
/*   Updated: 2023/12/13 10:24:42 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{

public:
	Dog(void);
	Dog(const Dog &src);
	~Dog(void);
	
	Dog	&operator=(const Dog &rhs);

	void	makeSound(void) const;

	Brain	*getBrain(void) const;

private:
	Brain	*_brain;
};




#endif
