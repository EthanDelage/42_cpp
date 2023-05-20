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

int	main(void)
{
	std::string	levelId[] = {"DEBUG", "INFO", "WARNING", "ERROR", ""};
	Harl		harl;

	for (int i = 0; i <= 4; i++)
		harl.complain(levelId[i]);
}