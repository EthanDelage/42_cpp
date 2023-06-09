/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 00:19:00 by edelage           #+#    #+#             */
/*   Updated: 2023/06/10 00:19:00 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {

}

MateriaSource::MateriaSource(MateriaSource const &other) {
	*this = other;
}

MateriaSource::~MateriaSource() {}

MateriaSource &MateriaSource::operator=(MateriaSource const &other) {

	return (*this);
}
