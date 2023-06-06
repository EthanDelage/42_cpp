/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 21:08:00 by edelage           #+#    #+#             */
/*   Updated: 2023/06/01 21:08:00 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class Animal {

public:
	Animal();
	Animal(Animal const &other);
	~Animal();

	Animal &operator=(Animal const &other);

protected:
	std::string	type;

};

#endif