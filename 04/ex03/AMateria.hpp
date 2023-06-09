/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 11:46:00 by edelage           #+#    #+#             */
/*   Updated: 2023/06/09 11:46:00 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>

class AMateria {

public:
	AMateria();
	AMateria(std::string const &type);
	AMateria(AMateria const &other);
	virtual ~AMateria();

	AMateria &operator=(AMateria const &other);

	std::string const	&getType() const;

	virtual AMateria	*clone() const = 0;
//	virtual void		use(ICharacter &target);

protected:
	std::string	_type;

};

#endif