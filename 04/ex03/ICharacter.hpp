/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:37:00 by edelage           #+#    #+#             */
/*   Updated: 2023/06/09 16:37:00 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include "AMateria.hpp"
# include <string>

class ICharacter {

public:
	ICharacter();
	ICharacter(ICharacter const &other);
	virtual ~ICharacter() {};

	ICharacter &operator=(ICharacter const &other);

	virtual std::string	const	&getName() const = 0;
	virtual void				equip(AMateria *m) = 0;
	virtual void				unequip(int index) = 0;
	virtual void				use(int index, ICharacter &target) = 0;

private:
	AMateria	*materia[4];

};

#endif