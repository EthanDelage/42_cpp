/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 19:22:00 by edelage           #+#    #+#             */
/*   Updated: 2023/05/17 19:22:00 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>

static void	str_toupper(char *str);

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int i = 1; i < argc; i++)
			str_toupper(argv[i]);
	}
	std::cout << std::endl;
}

static void	str_toupper(char *str)
{
	for (int i = 0; str[i]; i++)
		std::cout << (char) toupper(str[i]);
}