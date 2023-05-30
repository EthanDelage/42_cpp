/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 23:38:00 by edelage           #+#    #+#             */
/*   Updated: 2023/05/24 23:38:00 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

class ClapTrap {

public:
	ClapTrap();
	ClapTrap(ClapTrap const &copy);
	ClapTrap(std::string name);
	~ClapTrap();

	ClapTrap &operator=(ClapTrap const &other);

	void			attack(std::string const &target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);
	void			setAttackDamage(unsigned int amount);
	unsigned int	getAttackDamage();

private:
	std::string		_name;
	unsigned int	_hitPoints;
	unsigned int	_energyPoints;
	unsigned int	_attackDamage;

};

#endif