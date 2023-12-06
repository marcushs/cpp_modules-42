/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:06:42 by hleung            #+#    #+#             */
/*   Updated: 2023/12/06 18:13:15 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed
{

public:
	Fixed(void);
	Fixed(const Fixed &src);
	Fixed(const int value);
	Fixed(const float value);
	~Fixed();

	Fixed	&operator=(const Fixed &rhs);
	int		get_rawBits(void) const;
	void	set_rawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;

private:
	int					_rawBits;
	static const int	_nbFractionalBits;
};

std::ostream	&operator<<(std::ostream &o, const Fixed &rhs);

#endif
