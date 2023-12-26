/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 17:13:30 by hleung            #+#    #+#             */
/*   Updated: 2023/12/24 20:46:26 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP
# include <string>
# include "AForm.hpp"

class AForm;
class Intern
{
	//looser exception specification on overriding virtual function error when tried to create new constructor to take argument
	class	NoFormException : public std::exception
	{
		public:
			const char* what() const throw() {return "No matching form";}
	};
	
public:
	Intern(void);
	Intern(const Intern &src);
	~Intern(void);

	Intern	&operator=(const Intern &rhs);
	AForm	*makeForm(const std::string &name , const std::string &target) const;
};

#endif
