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
	Zombie *zombie = newZombie("Foo");

	zombie->announce();
	delete zombie;
	randomChump("Foo1");
	randomChump("Foo2");
}