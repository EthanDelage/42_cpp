/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 22:16:00 by edelage           #+#    #+#             */
/*   Updated: 2023/06/15 22:16:00 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "Array.hpp"
#include <iostream>
#include <string>

int main() {
	{
		Array<int> myArray(5);

		Array<int> secondArray = myArray;
		for (int i = 0; i < 5; ++i) {
			myArray[i] = i;
		}
		for (int i = 0; i < 4; ++i) {
			std::cout << myArray[i] << ", ";
		}
		std::cout << myArray[4] << std::endl;
		try {
			myArray[5] = 12;
		}
		catch (std::exception &e) {
			std::cerr << "you're trying to access an unallocated value" << std::endl;
		}
	}
	{
		Array<char> myArray(2);

		myArray[0] = 'o';
		myArray[1] = 'p';
		std::cout << myArray[0] << std::endl;
		std::cout << myArray[1] << std::endl;
	}
	return (0);
}
