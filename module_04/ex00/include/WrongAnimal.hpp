/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 08:08:36 by hleung            #+#    #+#             */
/*   Updated: 2023/12/13 08:11:01 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP
# include <string>

class WrongAnimal
{

public:
	WrongAnimal(void);
	WrongAnimal(const WrongAnimal &src);
	~WrongAnimal(void);
	
	WrongAnimal	&operator=(const WrongAnimal &rhs);
	std::string getType(void) const;

	void	makeSound(void) const;
	
protected:
	std::string	_type;
	
};

#endif
