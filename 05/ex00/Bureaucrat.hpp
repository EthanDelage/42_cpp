/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethan <ethan@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 23:22:00 by ethan             #+#    #+#             */
/*   Updated: 2023/06/10 23:22:00 by ethan            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <exception>
# include <iostream>

class Bureaucrat {

public:
	Bureaucrat();
	Bureaucrat(std::string name, unsigned int grade);
	Bureaucrat(Bureaucrat const &other);
	~Bureaucrat();

	Bureaucrat &operator=(Bureaucrat const &other);

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

	std::string		getName() const;
	unsigned int	getGrade() const;
	void			incrementGrade();
	void			decreaseGrade();

private:
	std::string	const	_name;
	unsigned			_grade;

};

std::ostream	&operator<<(std::ostream &os, Bureaucrat const &B);

#endif