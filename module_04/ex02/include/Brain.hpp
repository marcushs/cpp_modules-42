/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 08:46:37 by hleung            #+#    #+#             */
/*   Updated: 2023/12/13 09:35:07 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <string>

class Brain
{

public:
	Brain(void);
	Brain(const Brain &src);
	~Brain(void);

	Brain		&operator=(const Brain &rhs);
	void		setIdea(unsigned int i, std::string idea);
	std::string	getIdea(unsigned int i) const;

private:
	std::string	_ideas[100];
};




#endif
