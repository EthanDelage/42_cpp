/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:21:00 by edelage           #+#    #+#             */
/*   Updated: 2023/06/15 15:21:00 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>

Base::~Base() {}

Base *Base::generate() {
	int randomNumber = rand() % 3;
	Base *ptr;

	if (randomNumber == 0) {
		std::cout << "Create A" << std::endl;
		ptr = new A();
	}
	else if (randomNumber == 1) {
		std::cout << "Create B" << std::endl;
		ptr = new B();
	}
	else
	{
		std::cout << "Create C" << std::endl;
		ptr = new C();
	}
	return (ptr);
}

void Base::identify(Base *ptr) {
	std::cout << "Type with ptr: ";
	if (dynamic_cast<A *>(ptr))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(ptr))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(ptr))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown" << std::endl;
}

void Base::identify(Base &ref) {
	std::cout << "Type with ref: ";
	try {
		(void) dynamic_cast<A &>(ref);
		std::cout << "A" << std::endl;
		return ;
	}
	catch (const std::bad_cast &e) {}
	try {
		(void) dynamic_cast<B &>(ref);
		std::cout << "B" << std::endl;
		return ;
	}
	catch (const std::bad_cast &e) {}
	try {
		(void) dynamic_cast<C &>(ref);
		std::cout << "C" << std::endl;
		return ;
	}
	catch (const std::bad_cast &e) {}
	std::cout << "Unknown" << std::endl;
}
