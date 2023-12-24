/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 09:58:31 by hleung            #+#    #+#             */
/*   Updated: 2023/12/24 19:16:38 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP
# include <string>
# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;
class AForm
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
	class FormNotSignedException : public std::exception
	{
	public:
		const char* what() const throw() {return "Form Not Signed Yet!";}
	};
	
	class ExecutorGradeTooLowException : public std::exception
	{
	public:
		const char* what() const throw() {return "Executor Grade too low!";}
	};
	
	AForm(void);
	AForm(const std::string name, const int gradeToSign, const int gradeToExec);
	AForm(const AForm &src);
	virtual ~AForm(void);

	AForm	&operator=(const AForm &rhs);

	const std::string	&getName(void) const;
	bool				getIsSigned(void) const;
	int					getGradeToSign(void) const;
	int					getGradeToExec(void) const;

	void	beSigned(const Bureaucrat &bureaucrat);

	virtual void	execute(const Bureaucrat &executor) const = 0;

private:
	const std::string	_name;
	bool				_isSigned;
	const int			_gradeToSign;
	const int			_gradeToExec;
};

std::ostream	&operator<<(std::ostream &o, const AForm &rhs);

#endif
