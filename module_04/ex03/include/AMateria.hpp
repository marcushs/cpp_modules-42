/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:08:34 by hleung            #+#    #+#             */
/*   Updated: 2023/12/18 13:14:02 by hleung           ###   ########.fr       */
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
	std::string const	&getType(void) const; 
	virtual AMateria	*clone(void) const = 0;
	virtual void		use(ICharacter &target);
	bool	isLearned;

protected:
	std::string	_type;

};

#endif
