/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 20:33:00 by edelage           #+#    #+#             */
/*   Updated: 2023/05/17 20:33:00 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact {

private:
	std::string	firstName;
	std::string	lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkestSecret;

public:
	Contact();
	~Contact();

	void		setFirstName(std::string);
	std::string	getFirstName();
	void		setLastName(std::string);
	std::string	getLastName();
	void		setNickName(std::string);
	std::string	getNickName();
	void		setPhoneNumber(std::string);
	void		setDarkestSecret(std::string);
	void		toString();
};

#endif
