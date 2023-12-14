/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:18:29 by hleung            #+#    #+#             */
/*   Updated: 2023/12/14 12:43:40 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP
# include <string>
# include "AMateria.hpp"

class Ice : public AMateria
{

public:
	Ice(void);
	Ice(const Ice &src);
	~Ice(void);

	Ice &operator=(const Ice &rhs);
	AMateria &operator=(const AMateria &rhs);
	Ice	*clone(void) const;
	void	use(ICharacter &target);
};

#endif
