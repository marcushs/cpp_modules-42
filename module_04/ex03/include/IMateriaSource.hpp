/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 08:21:40 by hleung            #+#    #+#             */
/*   Updated: 2023/12/18 08:22:39 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

class AMateria;
class IMateriaSource
{
	public:
	virtual				~IMateriaSource() {}
	virtual void		learnMateria(AMateria *) = 0;
	virtual AMateria	*createMateria(std::string const &type) = 0;
};
