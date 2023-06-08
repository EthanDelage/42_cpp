/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 21:43:00 by edelage           #+#    #+#             */
/*   Updated: 2023/06/01 21:43:00 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog: public Animal{

public:
	Dog();
	Dog(Dog const &other);
	~Dog();

	Dog &operator=(Dog const &other);

	void	makeSound() const;

private:
	Brain	*_Brain;

};

#endif