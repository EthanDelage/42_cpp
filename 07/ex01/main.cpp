/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 21:32:00 by edelage           #+#    #+#             */
/*   Updated: 2023/06/15 21:32:00 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "iter.hpp"

template<typename T>
T		triple(T value);
template<typename T>
void	displayArray(T *array, size_t size);
char	ft_toupper(char c);

int main() {
	{
		int array[5];

		for (int i = 0; i < 5; ++i) {
			array[i] = i;
		}
		displayArray(array, 5);
		::iter(array, 5, &triple);
		displayArray(array, 5);
	}
	std::cout << std::endl;
	{
		float	array[5];

		for (int i = 0; i < 5; ++i) {
			array[i] = i + 0.5 * i;
		}
		displayArray(array, 5);
		::iter(array, 5, &triple);
		displayArray(array, 5);
	}
	std::cout << std::endl;
	{
		char	word[] = "Hello world!";

		std::cout << word << std::endl;
		::iter(word, strlen(word), &ft_toupper);
		std::cout << word << std::endl;
	}

	return (0);
}

template<typename T>
T	triple(T value) {
	return (value * 3);
}

template<typename T>
void	displayArray(T *array, size_t size) {
	std::cout << "Array: ";
	for (size_t i = 0; i < (size - 1); ++i) {
		std::cout << array[i] << ", ";
	}
	std::cout << array[size - 1] << std::endl;
}

char	ft_toupper(char c) {
	return (toupper(c));
}
