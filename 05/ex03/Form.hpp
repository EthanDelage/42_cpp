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
	Form(std::string name, unsigned int gradeToSign, unsigned int gradeToExecute);
	Form(Form const &other);
	virtual ~Form();

	Form &operator=(Form const &other);

	class GradeTooHighException: public std::exception {
	public:
		const char	*what() const throw() {
			return ("Bureaucrat's grade is too high!");
		}
	};
	class GradeTooLowException: public std::exception {
	public:
		const char	*what() const throw() {
			return ("Bureaucrat's grade is too low!");
		}
	};
	class FormNotSigned {
	public:
		const char	*what() const throw() {
			return ("Form is not signed");
		}
	};

	virtual void			beSigned(Bureaucrat signatory);
	virtual void			execute(Bureaucrat const &executor) const = 0;
	std::string				getName() const;
	bool					getIsSigned() const;
	void					setIsSigned(bool value);
	unsigned int			getGradeToSign() const;
	unsigned int			getGradeToExecute() const;

private:
	std::string const	_name;
	bool				_isSigned;
	unsigned int const	_gradeToSign;
	unsigned int const	_gradeToExecute;

};

std::ostream	&operator<<(std::ostream &os, Form const &F);

#endif