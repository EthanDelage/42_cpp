/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 01:58:00 by edelage           #+#    #+#             */
/*   Updated: 2023/06/15 01:58:00 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "data.hpp"
#include "Serializer.hpp"
#include <iostream>

int	main() {
	Data		*dataPtr = new Data;
	uintptr_t	ptr;

	std::cout << "dataPtr: " << dataPtr << std::endl;
	ptr = Serializer::serialize(dataPtr);
	std::cout << "ptr: " << ptr << std::endl;
	std::cout << "ptr: 0x" << std::hex << ptr << std::endl;
	dataPtr = Serializer::deserialize(ptr);
	std::cout << "dataPtr: " << dataPtr << std::endl;
	delete dataPtr;
}
