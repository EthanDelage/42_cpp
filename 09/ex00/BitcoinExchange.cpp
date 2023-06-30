/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:09:00 by edelage           #+#    #+#             */
/*   Updated: 2023/06/29 16:09:00 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "BitcoinExchange.hpp"

#include <cstring>
#include <iostream>

BitcoinExchange::BitcoinExchange() {
	parseData();
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::parseData() {
	const char		delimiter[] = " ";
	std::ifstream	dataFile(DATA_FILE);
	std::string		date;
	float			value;

	if (!dataFile.is_open())
		throw std::runtime_error(std::string("Can't open ") + DATA_FILE);
	
}