/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 02:45:00 by edelage           #+#    #+#             */
/*   Updated: 2023/06/14 02:45:00 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Form.hpp"

# include <string>

class PresidentialPardonForm: public Form {

public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(PresidentialPardonForm const &other);
	~PresidentialPardonForm();

	PresidentialPardonForm &operator=(PresidentialPardonForm const &other);

	void	execute(Bureaucrat const &executor) const;

private:
	std::string	_target;

};

#endif