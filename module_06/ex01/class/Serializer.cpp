/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 21:01:39 by hleung            #+#    #+#             */
/*   Updated: 2023/12/27 21:41:41 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Serializer.hpp"

/*------------------------------- Constructors -------------------------------*/

Serializer::Serializer() {}

Serializer::Serializer(const Serializer &src) {*this = src;}

/*-------------------------------- Destructor --------------------------------*/

Serializer::~Serializer() {}

/*--------------------------------- Overload ---------------------------------*/

Serializer	&Serializer::operator=(const Serializer &rhs) {static_cast<void>(rhs); return *this;}

/*----------------------------- Member Functions -----------------------------*/

uintptr_t	Serializer::serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data	*Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}
