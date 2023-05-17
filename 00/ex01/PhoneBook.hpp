/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 20:32:00 by edelage           #+#    #+#             */
/*   Updated: 2023/05/17 20:32:00 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

# define MAX_CONTACT	8
# define CELL_WIDTH		10

class PhoneBook {

private:
	Contact		contactList[MAX_CONTACT];
	int			totalContactAdd;

public:
	PhoneBook();
	void	addContact();
	void	searchContact();

};

#endif
