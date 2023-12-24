/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 09:28:13 by hleung            #+#    #+#             */
/*   Updated: 2023/12/22 12:39:25 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP
# include "AForm.hpp"
# include <string>
# define RESET "\033[0m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"


class AForm;
class ShrubberyCreationForm : public AForm
{
	
	class FileNotOpenedException : public std::exception
	{
	public:
		const char* what() const throw() {return "File Cannot Be Created Or Opened!";}
	};
		
public:
	ShrubberyCreationForm(void);
	ShrubberyCreationForm(const std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm &src);
	~ShrubberyCreationForm(void);

	ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &rhs);

	const std::string	&getTarget(void) const;

	void	execute(const Bureaucrat &executor) const;

private:
	std::string	_target;
};

std::ostream	&operator<<(std::ostream &o, const ShrubberyCreationForm &rhs);

#endif
