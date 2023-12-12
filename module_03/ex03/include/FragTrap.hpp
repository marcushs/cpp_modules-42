/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:18:04 by hleung            #+#    #+#             */
/*   Updated: 2023/12/12 16:30:35 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{

public:
	FragTrap(void);
	FragTrap(const std::string name);
	FragTrap(const FragTrap &src);
	~FragTrap(void);

	void	highFiveGuys(void);

	unsigned int	getStartHitPoints(void) const;
	unsigned int	getStartEnergyPoints(void) const;
	unsigned int	getStartAttackDamage(void) const;

protected:

	unsigned int	_startHitPoints;
	unsigned int	_startEnergyPoints;
	unsigned int	_startAttackDamage;
};

#endif
