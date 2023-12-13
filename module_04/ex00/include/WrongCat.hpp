/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 08:09:16 by hleung            #+#    #+#             */
/*   Updated: 2023/12/13 08:13:09 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_CAT_HPP
# define WRONG_CAT_HPP
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{

public:
	WrongCat(void);
	WrongCat(const WrongCat &src);
	~WrongCat(void);
	
	WrongCat	&operator=(const WrongCat &rhs);

	void	makeSound(void) const;
};


#endif
