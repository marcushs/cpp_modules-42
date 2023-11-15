/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:32:03 by hleung            #+#    #+#             */
/*   Updated: 2023/11/14 12:11:00 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

class	Contact
{

public:
	Contact(void);
	~Contact(void);
	static int		getNbContact(void);
	static void		incrementNbContact(void);
	std::string		getFirstName(void) const;
	std::string		getLastName(void) const;
	std::string		getNickName(void) const;
	std::string		getPhoneNumber(void) const;
	std::string		getSecret(void) const;
	void			setFirstName(std::string fn);
	void			setLastName(std::string ln);
	void			setNickName(std::string nn);
	void			setPhoneNumber(std::string pn);
	void			setSecret(std::string sec);

private:
	static int	_nbContact;
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickName;
	std::string	_phoneNumber;
	std::string	_secret;
};

#endif
