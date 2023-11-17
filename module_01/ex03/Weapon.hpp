/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:35:44 by hleung            #+#    #+#             */
/*   Updated: 2023/11/17 09:42:09 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _WEAPON_HPP_
# define _WEAPON_HPP_
# include <string>

class Weapon
{

public:

	Weapon(std::string const type);
	~Weapon();

	std::string	const &getType(void) const;
	void		setType(std::string const type);

private:

	std::string	_type;
};



#endif
