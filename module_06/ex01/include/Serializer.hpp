/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 21:02:10 by hleung            #+#    #+#             */
/*   Updated: 2023/12/27 21:40:22 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP
# include "Data.hpp"
# include <stdint.h>

class Serializer
{
private:
	Serializer();
	Serializer(const Serializer &src);
	~Serializer();

	Serializer	&operator=(const Serializer &rhs);

public:
	static	uintptr_t	serialize(Data *ptr);
	static	Data		*deserialize(uintptr_t raw);
};



#endif
