/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 09:43:16 by hleung            #+#    #+#             */
/*   Updated: 2023/12/11 10:58:58 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <string>
# include <iostream>

class ClapTrap
{

public:
	ClapTrap(void);
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &src);
	~ClapTrap(void);

	ClapTrap			&operator=(const ClapTrap &rhs);
	void				attack(const std::string &target);
	void				takeDamage(unsigned int amount);
	void				beRepaired(unsigned int amount);
	
	const std::string	&getName(void) const;
	unsigned int		getHitPoints(void) const;
	unsigned int		getEnergyPoints(void) const;
	unsigned int		getAttackDamage(void) const;

	int					isDead(void) const;
private:
	std::string		_name;
	unsigned int	_hitPoints;
	unsigned int	_energyPoints;
	unsigned int	_attackDamage;
};

std::ostream	&operator<<(std::ostream &o, const ClapTrap &rhs);

#endif
