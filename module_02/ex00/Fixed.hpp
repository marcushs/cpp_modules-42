/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:06:42 by hleung            #+#    #+#             */
/*   Updated: 2023/12/06 15:39:26 by hleung           ###   ########.fr       */
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
	int		getRawBits(void) const;
	void	setRawBits(int const raw);

private:
	int					_fpValue;
	static const int	_nbBits;
};

#endif
