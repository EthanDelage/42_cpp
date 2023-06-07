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
# include "Point.hpp"

int	main(void)
{
	const Point	A = Point(2, 2);
	const Point	B = Point(4, 0);
	const Point	C = Point(0, 1);
	const Point	P = Point(1.5f, 1.3f);

	if (Point::bsp(A, B, C, P))
		std::cout << "Point in triangle" << std::endl;
	else
		std::cout << "Point outside triangle" << std::endl;

	const Point	D = Point(2, 1);
	const Point	E = Point(1.5f, 2);
	const Point	F = Point(4, 2.5f);
	const Point	M = Point(1, 1);

	if (Point::bsp(D, E, F, M))
		std::cout << "Point in triangle" << std::endl;
	else
		std::cout << "Point outside triangle" << std::endl;
}
