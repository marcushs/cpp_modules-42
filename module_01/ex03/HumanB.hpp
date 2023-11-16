/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:35:37 by hleung            #+#    #+#             */
/*   Updated: 2023/11/16 16:40:30 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <string>

class HumanB
{

public:
	HumanB(std::string name);
	~HumanB();
	void	attack(void) const;
	void	setWeapon(Weapon wp);

private:
	std::string const	_name;
	Weapon				*_weapon;

};



