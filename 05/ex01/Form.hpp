/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 17:34:00 by edelage           #+#    #+#             */
/*   Updated: 2023/06/12 17:34:00 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <exception>
# include <iostream>

class Bureaucrat;

class Form {

public:
	Form();
	Form(std::string name, uint8_t gradeToSign, uint8_t gradeToExecute);
	Form(Form const &other);
	~Form();

	Form &operator=(Form const &other);

	class GradeTooHighException {};
	class GradeTooLowException {};

	void			beSigned(Bureaucrat signatory);
	std::string		getName() const;
	bool			getIsSigned() const;
	int				getGradeToSign() const;
	int				getGradeToExecute() const;

private:
	std::string const	_name;
	bool				_isSigned;
	uint8_t const		_gradeToSign;
	uint8_t const		_gradeToExecute;

};

std::ostream	&operator<<(std::ostream &os, Form const &F);

#endif