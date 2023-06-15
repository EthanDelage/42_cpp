/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:30:00 by edelage           #+#    #+#             */
/*   Updated: 2023/06/15 15:30:00 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

int	main() {
	srand(time(NULL));
	Base	*ptr;

	for (int i = 0; i < 10; ++i) {
		ptr = Base::generate();
		Base::identify(ptr);
		Base::identify(*ptr);
		std::cout << std::endl;
		delete ptr;
	}
}