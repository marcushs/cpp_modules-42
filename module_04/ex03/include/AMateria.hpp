/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:08:34 by hleung            #+#    #+#             */
/*   Updated: 2023/12/16 16:16:51 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_MATERIA_HPP
# define A_MATERIA_HPP
# include <string>
# include "ICharacter.hpp"

class	ICharacter;
class	AMateria
{

public:
	AMateria(void);
	AMateria(std::string const &type);
	AMateria(const AMateria &src);
	virtual ~AMateria(void);

	AMateria	&operator=(const AMateria &rhs);
	std::string const	&getType(void) const; //Returns the materia type
	virtual AMateria	*clone(void) const = 0;
	virtual void		use(ICharacter &target);

protected:
	std::string	_type;

};

#endif
