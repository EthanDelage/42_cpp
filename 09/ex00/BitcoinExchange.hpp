/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:09:00 by edelage           #+#    #+#             */
/*   Updated: 2023/06/29 16:09:00 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <fstream>
# include <string>
# include <map>

# define DATA_FILE	"data/data.csv"

class BitcoinExchange {

public:
	BitcoinExchange();
	BitcoinExchange(BitcoinExchange const &other);
	~BitcoinExchange();

	BitcoinExchange	&operator=(BitcoinExchange const &other);

	void	openInputFile(char const *inputFile);
	void	processLine();
	bool	eof();

private:
	std::map<std::string, float>	_data;
	std::ifstream					_inputFile;

	void	parseData();
	void	parseDataLine(std::ifstream &dataFile);
	bool	isValidDate(std::string date);
};

#endif