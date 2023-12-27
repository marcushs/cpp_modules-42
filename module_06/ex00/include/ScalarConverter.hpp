/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 18:42:20 by hleung            #+#    #+#             */
/*   Updated: 2023/12/26 19:20:52 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP
# include <string>

# define CHAR 0
# define INT 1
# define FLOAT 2
# define DOUBLE 3

class ScalarConverter
{
public:
	static void	convert(std::string s);

private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &src);
	~ScalarConverter();

	ScalarConverter	&operator=(const ScalarConverter &rhs);

};

#endif
