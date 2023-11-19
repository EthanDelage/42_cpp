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
#include <cstdlib>
#include <sys/stat.h>

BitcoinExchange::BitcoinExchange() {
	parseData();
}

BitcoinExchange::~BitcoinExchange() {
	if (_inputFile.is_open())
		_inputFile.close();
}

void BitcoinExchange::openInputFile(const char *inputFile) {
	std::string line;

	if (isDir(inputFile))
		throw std::runtime_error(std::string(inputFile) + " is a directory");
	_inputFile.open(inputFile);
	if (!_inputFile.is_open())
		throw std::runtime_error(std::string("Cannot open ") + inputFile);
	getline(_inputFile, line);
}

void BitcoinExchange::processLine() {
	std::string	line;
	std::string date;
	double		value;
	char 		*rest;
	std::map<std::string, float>::const_iterator	exchangeRate;

	getline(_inputFile, line);
	if (line.find(" | ", 0) != 10) {
		std::cerr << "Error: bad input => " << line << std::endl;
		return ;
	}
	date = line.substr(0, 10);
	value = strtod(line.c_str() + 13, &rest);
	if (*rest != '\0')
		std::cerr << "Error: bad input => " << line << std::endl;
	else if (!isValidDate(date))
		std::cerr << "Error: not valid date => " << date << std::endl;
	else if (value < 0)
		std::cerr << "Error: not a positive number" << std::endl;
	else if (value > 1000)
		std::cerr << "Error: too large number" << std::endl;
	else {
		exchangeRate = _data.upper_bound(date);
		if (exchangeRate != _data.begin())
			--exchangeRate;
		std::cout << date << " => " << value << " = "
				  << value * exchangeRate->second << std::endl; }
}

bool BitcoinExchange::eof() {
	return (_inputFile.eof());
}

void BitcoinExchange::parseData() {
	std::ifstream	dataFile(DATA_FILE);
	std::string		line;

	if (!dataFile.is_open())
		throw std::runtime_error(std::string("Cannot open ") + DATA_FILE);
	getline(dataFile, line);
	while (!dataFile.eof())
		parseDataLine(dataFile);
	dataFile.close();
}

void BitcoinExchange::parseDataLine(std::ifstream &dataFile) {
	std::string	line;
	std::string	date;
	float		value;

	getline(dataFile, date, ',');
	if (!dataFile.eof()) {
		getline(dataFile, line, '\n');
		value = strtod(line.c_str(), NULL);
		_data[date] = value;
	}
}

bool BitcoinExchange::isValidDate(std::string date) {
	static const int dayPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (date[4] != '-' || date[7] != '-')
		return (false);
	int year = strtod(date.c_str(), NULL);
	int month = strtod(date.c_str() + 5, NULL);
	int day = strtod(date.c_str() + 8, NULL);

	if (year >= 0
		&& month > 0 && month <= 12
		&& day >= 1 && day <= dayPerMonth[month - 1]
			+ (month == 2 && year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)))
		return (true);
	return (false);
}

bool BitcoinExchange::isDir(std::string const & dir) {
	struct stat st;

	if (stat(dir.c_str(), &st) == 0) {
		return S_ISDIR(st.st_mode);
	}
	return false;
}