/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 20:44:00 by edelage           #+#    #+#             */
/*   Updated: 2023/06/14 20:44:00 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#ifndef INTERN_HPP
# define INTERN_HPP

# include "Form.hpp"

# include <string>

class Intern {

public:
	Intern();
	Intern(Intern const &other);
	~Intern();

	Intern &operator=(Intern const &other);

	Form	*makeForm(std::string formName, std::string target);

};

#endif