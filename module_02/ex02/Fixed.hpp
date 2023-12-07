/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:22:19 by hleung            #+#    #+#             */
/*   Updated: 2023/12/07 10:23:57 by hleung           ###   ########.fr       */
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
	~Fixed(void);

	Fixed	&operator=(const Fixed &rhs);
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;

	int		operator>(const Fixed &rhs) const;
	int		operator<(const Fixed &rhs) const;
	int		operator>=(const Fixed &rhs) const;
	int		operator<=(const Fixed &rhs) const;
	int		operator==(const Fixed &rhs) const;
	int		operator!=(const Fixed &rhs) const;

	Fixed	operator+(const Fixed &rhs) const;
	Fixed	operator-(const Fixed &rhs) const;
	Fixed	operator*(const Fixed &rhs) const;
	Fixed	operator/(const Fixed &rhs) const;

	Fixed	&operator++(void); //pre inc
	Fixed	operator++(int); //post inc
	Fixed	&operator--(void); //pre dec
	Fixed	operator--(int); //post dec

	static Fixed	min(Fixed &a, Fixed &b);
	static Fixed	min(const Fixed &a, const Fixed &b);
	static Fixed	max(Fixed &a, Fixed &b);
	static Fixed	max(const Fixed &a, const Fixed &b);

private:

	int					_rawBits;
	static const int	_nbFractionalBits;
};

std::ostream	&operator<<(std::ostream &o, const Fixed &rhs);

#endif
