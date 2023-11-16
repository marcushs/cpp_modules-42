/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:57:12 by hleung            #+#    #+#             */
/*   Updated: 2023/11/16 13:05:23 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ZOMBIE_HPP_
# define _ZOMBIE_HPP_
# include <iostream>
# include <string>

class Zombie
{
	
public:

	Zombie(void);
	~Zombie(void);
	void	announce(void);
	void	setName(std::string name);

private:
	std::string	_name;
};

Zombie	*zombieHorde(int N, std::string name);

#endif
