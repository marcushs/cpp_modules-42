/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:22:19 by hleung            #+#    #+#             */
/*   Updated: 2023/12/06 18:24:31 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{

public:

	Fixed(void);
	Fixed(void);
	Fixed(void);
	~Fixed(void);

private:

	int					_rawBits;
	static const int	_nbFractionalBits;

}

#endif
