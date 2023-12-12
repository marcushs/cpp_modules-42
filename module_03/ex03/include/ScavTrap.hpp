/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:29:27 by hleung            #+#    #+#             */
/*   Updated: 2023/12/12 16:29:54 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{

public:
	ScavTrap(void);
	ScavTrap(const std::string name);
	ScavTrap(const ScavTrap &src);
	~ScavTrap(void);

	void	attack(const std::string &target);
	void	guardGate(void);

	unsigned int	getStartHitPoints(void) const;
	unsigned int	getStartEnergyPoints(void) const;
	unsigned int	getStartAttackDamage(void) const;

protected:

	unsigned int	_startHitPoints;
	unsigned int	_startEnergyPoints;
	unsigned int	_startAttackDamage;
};

#endif
