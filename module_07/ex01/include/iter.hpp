/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:47:57 by hleung            #+#    #+#             */
/*   Updated: 2023/12/28 21:56:46 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP
# include <iostream>

template< typename T, typename L, typename F >
void	iter(const T *arr, const L len, F (*func)(const T))
{
	for (L i = 0; i < len; i++)
		func(arr[i]);
}

template< typename T >
void	print(T c)
{
	std::cout << c << ' ';
}
#endif
