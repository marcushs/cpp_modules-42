/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 07:30:45 by hleung            #+#    #+#             */
/*   Updated: 2023/12/18 13:38:18 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"

class Cat : public Animal
{

public:
	Cat(void);
	Cat(const Cat &src);
	~Cat(void);
	
	Cat	&operator=(const Cat &rhs);

	void	makeSound(void) const;
};




#endif
