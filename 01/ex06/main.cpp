/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 20:40:00 by edelage           #+#    #+#             */
/*   Updated: 2023/05/20 20:40:00 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "Harl.hpp"
#include <string>

int	main(int argc, char **argv)
{
	Harl	harl;
	if (argc != 2)
		return (1);

	std::string	str(argv[1]);
	harl.complain(str);
}