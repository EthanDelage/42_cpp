/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 08:48:00 by edelage           #+#    #+#             */
/*   Updated: 2023/06/17 08:48:00 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "Span.hpp"
#include <iostream>
#include <cstring>

int main() {
	{
		int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

		Span sp = Span(5);
		try {
			sp.addNumber(6);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);
			sp.addMultipleNumber(array, array + sizeof(array) / sizeof(int));
			std::cout << "shortest: " << sp.shortestSpan() << std::endl;
			std::cout << "longest: " << sp.longestSpan() << std::endl;
			std::cout << std::endl;
			sp.displaySpan();
		} catch (std::exception const &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		Span sp = Span(5);
		try {
			sp.addNumber(6);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);
			std::cout << "shortest: " << sp.shortestSpan() << std::endl;
			std::cout << "longest: " << sp.longestSpan() << std::endl;
			std::cout << std::endl;
			sp.displaySpan();
		} catch (std::exception const &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

		Span sp = Span(50);
		try {
			sp.addNumber(6);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);
			sp.addMultipleNumber(array, array + sizeof(array) / sizeof(int));
			std::cout << "shortest: " << sp.shortestSpan() << std::endl;
			std::cout << "longest: " << sp.longestSpan() << std::endl;
			std::cout << std::endl;
			sp.displaySpan();
		} catch (std::exception const &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		int array[10000];
		Span sp(11000);

		std::memset(array, 0, sizeof(array));
		try {
			sp.addMultipleNumber(array, array + sizeof(array) / sizeof(int));
			sp.addNumber(13);
			sp.addNumber(12);
			sp.addNumber(1);
			std::cout << "shortest: " << sp.shortestSpan() << std::endl;
			std::cout << "longest: " << sp.longestSpan() << std::endl;
		} catch (std::exception const &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	return (0);
}