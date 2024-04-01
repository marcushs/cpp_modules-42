/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:47:57 by hleung            #+#    #+#             */
/*   Updated: 2024/04/01 14:00:57 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template< typename T >
void	swap(T &x, T &y)
{
	T	tmp;

	tmp = x;
	x = y;
	y = tmp;
}

template< typename T >
const T	&max(const T &x, const T &y)
{
	return (x > y ? x : y);
}

template< typename T >
const T	&min(const T &x, const T &y)
{
	return (x < y ? x : y);
}
#endif
