/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 22:51:00 by edelage           #+#    #+#             */
/*   Updated: 2023/06/14 22:51:00 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "ScalarConverter.hpp"
#include <iostream>

int	main(int argc, char **argv) {
	if (argc != 2)
	{
		std::cerr << "Too few argument" << std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);
	return (0);
}