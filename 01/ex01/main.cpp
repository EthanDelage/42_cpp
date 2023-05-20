/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:21:00 by edelage           #+#    #+#             */
/*   Updated: 2023/05/20 13:21:00 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "Zombie.hpp"

int main()
{
	Zombie	*zombies= zombieHorde(7, "Foo");

	for (int i = 0; i < 7; i++)
		zombies[i].announce();
	delete[] zombies;
}