/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 21:40:00 by edelage           #+#    #+#             */
/*   Updated: 2023/05/17 21:40:00 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int	main()
{
	PhoneBook	phoneBook;
	std::string	userInput;

	std::cout << "My Awesome PhoneBook" << std::endl;
	while (1)
	{
		std::cout << std::endl << "PhoneBook >$ ";
		std::cin >> userInput;
		if (userInput == "ADD")
			phoneBook.addContact();
		else if (userInput == "SEARCH")
			phoneBook.searchContact();
		else if (userInput == "EXIT")
		{
			std::cout << std::endl << "Your contacts are lost forever !" << std::endl;
			return (0);
		}
		else
			std::cout << "Invalid command" << std::endl;
	}
}