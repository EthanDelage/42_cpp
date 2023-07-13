/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:04:00 by edelage           #+#    #+#             */
/*   Updated: 2023/07/01 15:04:00 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "PmergeMe.hpp"

#include <iostream>

int	main(int argc, char **argv) {
	if (argc < 2) {
		std::cerr << "Error" << std::endl;
		return (1);
	}
	try {
		PmergeMe	mergeMe(argc, argv);

		mergeMe.display();
	} catch (std::exception const &e) {
		std::cerr << "Error" << std::endl;
		return (1);
	}
}