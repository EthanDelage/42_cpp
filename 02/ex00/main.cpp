/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 00:36:00 by edelage           #+#    #+#             */
/*   Updated: 2023/05/21 00:36:00 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "Fixed.hpp"
#include <iostream>

int	main(void)
{
	Fixed	a;
	Fixed	b(a);
	Fixed	c;

	std::cout << "a " << a.getRawBits() << std::endl;
	std::cout << "b " << b.getRawBits() << std::endl;
	b.setRawBits(4);
	std::cout << std::endl << "b " << b.getRawBits() << std::endl;
	c = b;
	std::cout << "c " << c.getRawBits() << std::endl;
	c.setRawBits(8);
	std::cout << std::endl << "c " << c.getRawBits() << std::endl;
	return (0);
}
