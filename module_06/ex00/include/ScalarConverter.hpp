/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 18:42:20 by hleung            #+#    #+#             */
/*   Updated: 2023/12/25 19:06:21 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP
# include <string>

class ScalarConverter
{
public:
	static void	convert(const std::string &s);

private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &src);
	virtual ~ScalarConverter();

	ScalarConverter	&operator=(const ScalarConverter &rhs);

};




#endif
