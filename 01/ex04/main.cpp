/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 18:19:00 by edelage           #+#    #+#             */
/*   Updated: 2023/05/20 18:19:00 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include <fstream>
#include <iostream>
#include <cstring>

static void	searchAndReplace(char *strToFind, char *strToReplace,
				std::ifstream &inputFile, std::ofstream &outputFile);
static std::string	getFileContent(std::ifstream &file);

int	main(int argc, char **argv)
{
	std::ifstream	inputFile;
	std::ofstream	outputFile;
	std::string		outputFileName;

	if (argc != 4)
	{
		std::cerr << "./sed filename string_to_find string_to_replace" << std::endl;
		return (1);
	}
	inputFile.open(argv[1], std::fstream::in);
	if (!inputFile.is_open())
	{
		std::cout << "Can't open file" << std::endl;
		return (1);
	}
	outputFileName = argv[1];
	outputFileName.append(".replace");
	outputFile.open(outputFileName.c_str(), std::fstream::out);
	if (!outputFile.is_open())
	{
		inputFile.close();
		std::cout << "Can't create file" << std::endl;
		return (1);
	}
	searchAndReplace(argv[2], argv[3], inputFile, outputFile);
	outputFile.close();
}

static void	searchAndReplace(char *strToFind, char *strToReplace,
				std::ifstream &inputFile, std::ofstream &outputFile)
{
	std::string fileContent;
	size_t		index;

	fileContent = getFileContent(inputFile);
	inputFile.close();
	index = 0;
	while (index != fileContent.length() && index != std::string::npos)
	{
		index = fileContent.find(strToFind, index);
		if (index != std::string::npos)
		{
			fileContent.erase(index, strlen(strToFind));
			fileContent.insert(index, strToReplace);
		}
	}
	outputFile << fileContent;
}

static std::string	getFileContent(std::ifstream &file)
{
	char		buf;
	std::string	fileContent;

	while (file.get(buf))
		fileContent += buf;
	return (fileContent);
}
