/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 09:33:23 by hleung            #+#    #+#             */
/*   Updated: 2023/12/22 13:07:53 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ShrubberyCreationForm.hpp"
#include <fstream>


/*------------------------------- Constructors -------------------------------*/

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("Default ShrubberyCreationForm", 145, 137), _target("home"){}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src.getName() + ".Copy", 145, 137), _target(src._target) {}

/*-------------------------------- Destructor --------------------------------*/

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

/*--------------------------------- Overload ---------------------------------*/

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs) {(void)rhs; return *this;}

/*---------------------------------- Getter ----------------------------------*/
const std::string	&ShrubberyCreationForm::getTarget(void) const {return this->_target;}

/*----------------------------- Member Functions -----------------------------*/

void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	try
	{
		if (!this->getIsSigned())
			throw AForm::FormNotSignedException();
		if (executor.getGrade() > this->getGradeToExec())
			throw AForm::ExecutorGradeTooLowException();

		std::ofstream	ofs((this->_target + "_shrubbery").c_str());
		if (!ofs.good())
			throw ShrubberyCreationForm::FileNotOpenedException();
		ofs << "                         " << std::endl;
		ofs << YELLOW << "           _\\/_            " << RESET << std::endl;
		ofs << YELLOW << "            /\\           " << RESET << std::endl;
		ofs << GREEN << "           ****          " << RESET << std::endl;
		ofs << GREEN << "          **" << RED << "o" << GREEN << "***         " << RESET<< std::endl;
		ofs << GREEN << "         *" << CYAN << "o" << GREEN << "***" << MAGENTA "o" << GREEN << "**        " << RESET << std::endl;
		ofs << GREEN << "        ***" << YELLOW << "o" << GREEN << "**" << RED << "o" << BLUE << "o" << GREEN << "**" << RESET << std::endl;
		ofs << GREEN <<"       **" << RED "oo" << GREEN << "***" << CYAN "o" << GREEN << "**" << YELLOW << "o" << GREEN "*" << RESET << std::endl;
		ofs << MAGENTA << "      o" << GREEN << "***" << YELLOW << "o" << GREEN "****" << RED << "o" << GREEN << "****     " << RESET << std::endl;
		ofs << GREEN << "     *****" << YELLOW << "o" << GREEN << "**********    " << RESET << std::endl;
		ofs << GREEN << "    ************" << MAGENTA << "o" << GREEN << "**" << BLUE << "o" << RED << "o" << GREEN << "*" << RESET << std::endl;
		ofs << GREEN << "   ******" << CYAN << "o" << YELLOW << "o" << GREEN "***" << RED << "o" << GREEN << "*******" << RESET << "o" << std::endl;
		ofs << RED << "  o" << YELLOW "o" << GREEN << "*****" << MAGENTA << "o" << BLUE << "o" << YELLOW << "o" << GREEN << "*******" << RED 
		<< "o" << GREEN << "*" << CYAN << "o" << GREEN << "** " << std::endl;
		ofs << " ************************" << std::endl;
		ofs << "**************************" << std::endl;
		ofs << RED << "            ||           " << RESET << std::endl;
		ofs << RED << "            ||           " << RESET << std::endl;
		ofs << "                         " << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}


std::ostream	&operator<<(std::ostream &o, const ShrubberyCreationForm &rhs)
{
	o << "Form Name                : " << rhs.getName() << std::endl;
	o << "Form Is Signed           : " <<(rhs.getIsSigned() ? "Signed!" : "Not signed yet!") 
	<< std::endl;
	o << "Target                   : " << rhs.getTarget() << std::endl;
	o << "Required Grade To Sign   : " << rhs.getGradeToSign() << std::endl;
	o << "Required Grade To Execute: " << rhs.getGradeToExec() << std::endl;
	return o;
}

