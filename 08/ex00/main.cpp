/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 21:45:00 by edelage           #+#    #+#             */
/*   Updated: 2023/06/16 21:45:00 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "easyfind.hpp"
#include <iostream>
#include <list>
#include <vector>

int main() {
	{
		std::list<int>	myList;

		myList.push_back(12);
		myList.push_back(3);
		myList.push_back(42);
		myList.push_back(0);
		myList.push_back(-5);
		try {
			std::cout << easyfind(myList, -5) << " found" << std::endl;
		}
		catch (std::exception &e) {
			std::cout << "-5 not found" << std::endl;
		}
	}
	{
		std::list<int>	myList;

		myList.push_back(12);
		myList.push_back(3);
		myList.push_back(42);
		myList.push_back(0);
		myList.push_back(3);
		try {
			std::cout << easyfind(myList, -5) << " found" << std::endl;
		}
		catch (std::exception &e) {
			std::cout << "-5 not found" << std::endl;
		}
	}
	{
		int					array[] = {12, 23, 43, 89, 16};
		std::vector<int>	myVector(array, array + sizeof(array) / sizeof(int));
		try {
			std::cout << easyfind(myVector, 23) << " found" << std::endl;
		}
		catch (std::exception &e) {
			std::cout << "23 not found" << std::endl;
		}
	}
}