/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 00:19:00 by edelage           #+#    #+#             */
/*   Updated: 2023/06/10 00:19:00 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

# define NB_SLOTS	4

class MateriaSource: public IMateriaSource{

public:
	MateriaSource();
	MateriaSource(MateriaSource const &other);
	~MateriaSource();

	MateriaSource &operator=(MateriaSource const &other);

	void 		learnMateria(AMateria*);
	AMateria*	createMateria(std::string const & type);

private:
	AMateria	*_inventory[NB_SLOTS];

};

#endif