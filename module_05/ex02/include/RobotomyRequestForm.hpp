/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 13:15:38 by hleung            #+#    #+#             */
/*   Updated: 2023/12/22 14:15:27 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUEST_FORM
# define ROBOTOMY_REQUEST_FORM
# include "AForm.hpp"

class AForm;
class RobotomyRequestForm : public AForm
{

public:
	RobotomyRequestForm(void);
	RobotomyRequestForm(const std::string target);
	RobotomyRequestForm(const RobotomyRequestForm &src);
	~RobotomyRequestForm(void);

	RobotomyRequestForm	&operator=(const RobotomyRequestForm &rhs);

	const std::string	&getTarget(void) const;

	void	execute(const Bureaucrat &executor) const;

private:
	std::string	_target;
};

std::ostream	&operator<<(std::ostream &o, const RobotomyRequestForm &rhs);

#endif
