/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 21:08:00 by edelage           #+#    #+#             */
/*   Updated: 2023/06/01 21:08:00 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main() {
	Animal	*animals[10];
	for (int i = 0; i < 5; i++)
		animals[i] = new Dog();
	for (int i = 5; i < 10; i++)
		animals[i] = new Cat();

	for (int i = 0; i < 10; ++i) {
		animals[i]->makeSound();
		delete animals[i];
	}
	return 0;
}