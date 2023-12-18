/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 08:22:54 by hleung            #+#    #+#             */
/*   Updated: 2023/12/18 09:04:53 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIA_SOURCE_HPP
# define MATERIA_SOURCE_HPP
# include "AMateria.hpp"
# include "IMateriaSource.hpp"

class AMateria;
class IMateriaSource;

class MateriaSource : public IMateriaSource
{
public:
	MateriaSource(void);
	MateriaSource(const MateriaSource &src);
	~MateriaSource(void);

	MateriaSource	&operator=(const MateriaSource &rhs);
	void		learnMateria(AMateria *m);
	AMateria	*createMateria(const std::string &type);
	
private:
	static const unsigned int	_nbMateria = 4;
	AMateria	*_library[MateriaSource::_nbMateria];
};




#endif
