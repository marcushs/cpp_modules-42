/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 14:14:15 by hleung            #+#    #+#             */
/*   Updated: 2023/12/22 14:15:21 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_PARDON_FORM
# define PRESIDENTIAL_PARDON_FORM
# include "AForm.hpp"

class AForm;
class PresidentialPardonForm : public AForm
{

public:
	PresidentialPardonForm(void);
	PresidentialPardonForm(const std::string target);
	PresidentialPardonForm(const PresidentialPardonForm &src);
	~PresidentialPardonForm(void);

	PresidentialPardonForm	&operator=(const PresidentialPardonForm &rhs);

	const std::string	&getTarget(void) const;

	void	execute(const Bureaucrat &executor) const;

private:
	std::string	_target;
};

std::ostream	&operator<<(std::ostream &o, const PresidentialPardonForm &rhs);
#endif
