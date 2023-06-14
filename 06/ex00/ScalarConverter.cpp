/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 22:52:00 by edelage           #+#    #+#             */
/*   Updated: 2023/06/14 22:52:00 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "ScalarConverter.hpp"
#include <errno.h>
#include <iostream>
#include <math.h>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const &other) {
	*this = other;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &other) {
	(void) other;
	return (*this);
}

void ScalarConverter::convert(char *str) {
	char	*rest;
	bool	error;
	bool	containComma;

	double	conversion = strtod(str, &rest);
	if (strchr(str, '.') == NULL)
		containComma = false;
	else
		containComma = true;
	error = !isValidString(conversion, rest, containComma);
	display(conversion, error);
}

bool ScalarConverter::isValidString(double conversion, char *rest, bool containComma) {
	if (errno == ERANGE)
		return (false);
	else if ((isinf(conversion) || isnan(conversion))
		&& strcmp(rest, "f") == 0)
		return (true);
	else if (containComma && strcmp(rest, "f") == 0)
		return (true);
	else if (*rest != '\0')
		return (false);
	else if ((isinf(conversion) || isnan(conversion))
		&& *rest != '\0')
		return (false);
	return (true);
}

void ScalarConverter::display(double conversion, bool error) {
	std::cout << "char:\t";
	if (error
		|| isinf(conversion) || isnan(conversion)
		|| conversion > std::numeric_limits<char>::max()
		|| conversion < std::numeric_limits<char>::min())
		std::cout << "impossible" << std::endl;
	else if (isprint(static_cast<char>(conversion)))
		std::cout << "'" << static_cast<char>(conversion) << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	std::cout << "int:\t";
	if (error
		|| isinf(conversion) || isnan(conversion)
		|| conversion > std::numeric_limits<int>::max()
		|| conversion < std::numeric_limits<int>::min())
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(conversion) << std::endl;
	std::cout << "float:\t";
	if (!error && (isinf(conversion) || isnan(conversion)))
		std::cout << conversion << "f" << std::endl;
	else if (error
		|| conversion > std::numeric_limits<float>::max()
		|| conversion < std::numeric_limits<float>::lowest())
		std::cout << "impossible" << std::endl;
	else
	{
		std::cout << static_cast<float>(conversion);
		if (round(conversion) == conversion)
			std::cout << ".0";
		std::cout << "f" << std::endl;
	}
	std::cout << "double:\t";
	if (error)
		std::cout << "impossible" << std::endl;
	else
	{
		std::cout << conversion;
		if (round(conversion) == conversion
			&& !isinf(conversion) && !isnan(conversion))
			std::cout << ".0";
		std::cout << std::endl;
	}
}
