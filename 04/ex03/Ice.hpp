/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 11:57:00 by edelage           #+#    #+#             */
/*   Updated: 2023/06/09 11:57:00 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice: public AMateria {

public:
	Ice();
	Ice(Ice const &other);
	~Ice();

	Ice &operator=(Ice const &other);

	AMateria	*clone() const;
	void		use(ICharacter &target);

};

#endif