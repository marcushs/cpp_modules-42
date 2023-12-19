/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:14:28 by hleung            #+#    #+#             */
/*   Updated: 2023/12/19 10:26:43 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <string>
# include <exception>
# include <iostream>

class Bureaucrat
{

	class GradeTooHighException : public std::exception
	{
	public:
		const char* what() const throw() {return "Grade too high! Grade reset to 1";}
	};
	
	class GradeTooLowException : public std::exception
	{
	public:
		const char* what() const throw() {return "Grade too low! Grade reset to 150";}
	};
	
public:
	Bureaucrat(void);
	Bureaucrat(const std::string name, int grade);
	Bureaucrat(const Bureaucrat &src);
	~Bureaucrat(void);

	Bureaucrat	&operator=(const Bureaucrat &rhs);
	const std::string	&getName(void) const;
	int					getGrade(void) const;
	void				incrementGrade(void);
	void				decrementGrade(void);

private:
	const std::string	_name;
	int					_grade;
};

std::ostream	&operator<<(std::ostream &o, const Bureaucrat &rhs);

#endif
