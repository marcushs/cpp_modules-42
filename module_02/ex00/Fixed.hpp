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

class Fixed
{

public:
	Fixed(void);
	Fixed(const Fixed &src);
	~Fixed();

	Fixed	&operator=(const Fixed &rhs);
	int		get_rawBits(void) const;
	void	set_rawBits(int const raw);

private:
	int					_rawBits;
	static const int	_nbFractionalBits;
};

#endif
