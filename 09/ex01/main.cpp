/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:59:00 by edelage           #+#    #+#             */
/*   Updated: 2023/06/27 16:59:00 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "RPN.hpp"
#include <iostream>

int main(int argc, char **argv) {
	if (argc != 2 || !isValidInput(argv[1])) {
		std::cerr << "Error" << std::endl;
		return (1);
	}
	try {
		int result = calculateRPN(argv[1]);
		std::cout << result << std::endl;
	} catch (std::exception const &e) {
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return (0);
}