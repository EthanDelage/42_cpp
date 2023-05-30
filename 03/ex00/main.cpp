/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 23:37:00 by edelage           #+#    #+#             */
/*   Updated: 2023/05/24 23:37:00 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "ClapTrap.hpp"

int main() {
	ClapTrap clap("clap");
	ClapTrap trap("trap");

	clap.setAttackDamage(2);
	trap.setAttackDamage(10);

	clap.attack("trap");
	trap.takeDamage(clap.getAttackDamage());

	trap.beRepaired(1);
	trap.beRepaired(1);
	trap.beRepaired(1);
	trap.attack("clap");
	clap.takeDamage(trap.getAttackDamage());
	clap.beRepaired(4);
	return (0);
}