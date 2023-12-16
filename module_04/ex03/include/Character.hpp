/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 08:19:16 by hleung            #+#    #+#             */
/*   Updated: 2023/12/16 16:36:27 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include "ICharacter.hpp"

class Character : public ICharacter
{
public:
	Character(void);
	Character(const std::string name);
	Character(const Character &src);
	~Character(void);

	Character	&operator=(const Character &rhs);

	std::string const	&getName(void) const;
	AMateria			*getMateria(int i) const;

	void	equip(AMateria* m);
	void	unequip(int idx);
	void	use(int idx, ICharacter& target);


private:

	std::string			_name;
	static const int	_nbItem = 4;
	AMateria			*_inventory[Character::_nbItem];
	unsigned int		_floorSize;
	AMateria			**_floor;
};




#endif
