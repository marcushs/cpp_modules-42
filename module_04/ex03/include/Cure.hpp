/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:18:32 by hleung            #+#    #+#             */
/*   Updated: 2023/12/14 12:43:52 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP
# include <string>
# include "AMateria.hpp"

class Cure : public AMateria
{

public:
	Cure(void);
	Cure(const Cure &src);
	~Cure(void);

	Cure &operator=(const Cure &rhs);
	AMateria &operator=(const AMateria &rhs);
	Cure	*clone(void) const;
	void	use(ICharacter &target);
};

#endif
