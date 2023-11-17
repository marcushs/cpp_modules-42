/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:35:32 by hleung            #+#    #+#             */
/*   Updated: 2023/11/17 08:57:59 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class HumanA
{

public:

	HumanA(std::string name, Weapon &wp);
	~HumanA();
	void	attack(void) const;

private:

	std::string const	_name;
	Weapon				&_weapon;
};


