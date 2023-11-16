/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:35:44 by hleung            #+#    #+#             */
/*   Updated: 2023/11/16 16:05:48 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _WEAPON_HPP_
# define _WEAPON_HPP_
# include <string>

class Weapon
{

public:

	Weapon(std::string type);
	~Weapon();

	std::string	getType(void) const;
	void		setType(std::string type);

private:

	std::string	_type;
};



#endif
