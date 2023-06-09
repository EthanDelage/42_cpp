/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 20:35:00 by edelage           #+#    #+#             */
/*   Updated: 2023/06/09 20:35:00 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include <string>

# define NB_SLOTS	4

class Character: public ICharacter {

public:
	Character();
	Character(std::string name);
	Character(Character const &other);
	~Character();

	Character &operator=(Character const &other);

	std::string	const	&getName() const = 0;
	void				equip(AMateria *m) = 0;
	void				unequip(int index) = 0;
	void				use(int index, ICharacter &target) = 0;

private:
	std::string	_name;
	AMateria	*_inventory[NB_SLOTS];

};

#endif