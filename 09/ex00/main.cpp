/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:08:00 by edelage           #+#    #+#             */
/*   Updated: 2023/06/29 16:08:00 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Error: couldn't open file" << std::endl;
		return (1);
	}
	try {
		BitcoinExchange bitcoin;

		bitcoin.openInputFile(argv[1]);
		while (!bitcoin.eof())
			bitcoin.processLine();
	} catch (std::exception const &e) {
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return (0);
}