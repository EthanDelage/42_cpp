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
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main() {
	ClapTrap clap("clap");
	ClapTrap trap("trap");
	ScavTrap scav("scav");
	ScavTrap scav1("scav");
	FragTrap frag("frag");
	DiamondTrap diamond("diamond");
	DiamondTrap diamondTest = diamond;


	clap.setAttackDamage(2);
	trap.setAttackDamage(10);

	clap.attack("trap");
	trap.takeDamage(clap.getAttackDamage());

	trap.beRepaired(1);
	trap.attack("clap");
	clap.takeDamage(trap.getAttackDamage());
	clap.beRepaired(4);

	scav.attack("trap");
	trap.takeDamage(scav.getAttackDamage());
	trap.attack("scav");
	scav.guardGate();

	frag.attack("scav");
	scav.takeDamage(frag.getAttackDamage());

	frag.highFivesGuys();

	diamond.attack("NULL");
	diamond.whoAmI();
	diamondTest.whoAmI();

	return (0);
}