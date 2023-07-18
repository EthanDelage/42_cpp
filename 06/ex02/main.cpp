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
#include <iostream>
#include <cstdlib>

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