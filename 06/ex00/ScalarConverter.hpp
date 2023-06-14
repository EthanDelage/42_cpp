/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 22:52:00 by edelage           #+#    #+#             */
/*   Updated: 2023/06/14 22:52:00 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

class ScalarConverter {

public:
	ScalarConverter();
	ScalarConverter(ScalarConverter const &other);
	~ScalarConverter();

	ScalarConverter &operator=(ScalarConverter const &other);

	static void	convert(char *str);
	static bool	isValidString(double conversion, char *rest, bool containComma);
	static void	display(double conversion, bool error);

};

#endif