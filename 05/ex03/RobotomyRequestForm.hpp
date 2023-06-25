/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 02:26:00 by edelage           #+#    #+#             */
/*   Updated: 2023/06/14 02:26:00 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "Form.hpp"

# include <string>

class RobotomyRequestForm: public Form{

public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(RobotomyRequestForm const &other);
	~RobotomyRequestForm();

	RobotomyRequestForm &operator=(RobotomyRequestForm const &other);

	void	execute(Bureaucrat const &executor) const;

private:
	std::string	_target;

};

#endif