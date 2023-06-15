/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 01:58:00 by edelage           #+#    #+#             */
/*   Updated: 2023/06/15 01:58:00 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include "data.hpp"
# include <cstdint>

class Serializer {

public:
	Serializer();
	Serializer(Serializer const &other);
	~Serializer();

	Serializer &operator=(Serializer const &other);

	static uintptr_t	serialize(Data *ptr);
	static Data			*deserialize(uintptr_t ptr);

private:

};

#endif