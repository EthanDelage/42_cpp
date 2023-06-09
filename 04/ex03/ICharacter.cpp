/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:37:00 by edelage           #+#    #+#             */
/*   Updated: 2023/06/09 16:37:00 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "ICharacter.hpp"

ICharacter::ICharacter() {

}

ICharacter::ICharacter(ICharacter const &other) {
	*this = other;
}

ICharacter::~ICharacter() {}

ICharacter &ICharacter::operator=(ICharacter const &other) {

	return (*this);
}
