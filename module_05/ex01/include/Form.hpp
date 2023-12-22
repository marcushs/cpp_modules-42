/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 09:58:31 by hleung            #+#    #+#             */
/*   Updated: 2023/12/22 08:55:56 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# include <string>
# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;
class Form
{

	class GradeTooHighException : public std::exception
	{
	public:
		const char* what() const throw() {return "Grade too high!";}
	};
	
	class GradeTooLowException : public std::exception
	{
	public:
		const char* what() const throw() {return "Grade too low!";}
	};

public:
	Form(void);
	Form(const std::string name, const int gradeToSign, const int gradeToExec);
	Form(const Form &src);
	~Form(void);

	Form	&operator=(const Form &rhs);

	const std::string	&getName(void) const;
	bool				getIsSigned(void) const;
	int					getGradeToSign(void) const;
	int					getGradeToExec(void) const;

	void	beSigned(const Bureaucrat &bureaucrat);

private:
	const std::string	_name;
	bool				_isSigned;
	const int			_gradeToSign;
	const int			_gradeToExec;
};

std::ostream	&operator<<(std::ostream &o, const Form &rhs);

#endif
