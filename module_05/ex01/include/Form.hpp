/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 09:58:31 by hleung            #+#    #+#             */
/*   Updated: 2023/12/19 10:39:46 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# include <string>
# include <iostream>

class Form
{

	class GradeTooHighException : public std::exception
	{
	public:
		const char* what() const throw() {return "Grade too high! Grade reset to 0";}
	};
	
	class GradeTooLowException : public std::exception
	{
	public:
		const char* what() const throw() {return "Grade too low! Grade reset to 150";}
	};

public:
	Form(void);
	Form(const Form &src);
	~Form(void);

	Form	&operator=(const Form &rhs);

	const std::string	&getName(void) const;
	bool				getIsSigned(void) const;
	const int			getGradeToSign(void) const;
	const int			getGradeToExec(void) const;

private:
	const std::string	_name;
	bool				_isSigned;
	const int			_gradeToSign;
	const int			_gradeToExec;
};

std::ostream	&operator<<(std::ostream &o, const Form &rhs);

#endif
