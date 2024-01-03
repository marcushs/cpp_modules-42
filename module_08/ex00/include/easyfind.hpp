/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 20:49:15 by hleung            #+#    #+#             */
/*   Updated: 2024/01/03 14:36:18 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <algorithm>
# include <iostream>

template < typename T >
typename T::const_iterator	easyfind(const T &container, const int &toFind)
{
	typename T::const_iterator i = std::find(container.begin(), container.end(), toFind);
	if (i == container.end())
		throw std::exception();
	std::cout << "Found value " << *i << std::endl;
	return i;
}
#endif
