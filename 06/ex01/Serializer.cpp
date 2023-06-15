/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 01:58:00 by edelage           #+#    #+#             */
/*   Updated: 2023/06/15 01:58:00 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(Serializer const &other) {
	*this = other;
}

Serializer::~Serializer() {}

Serializer &Serializer::operator=(Serializer const &other) {
	(void) other;
	return (*this);
}

uintptr_t Serializer::serialize(Data *ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serializer::deserialize(uintptr_t ptr) {
	return (reinterpret_cast<Data *>(ptr));
}
