/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 21:33:00 by edelage           #+#    #+#             */
/*   Updated: 2023/06/15 21:33:00 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template<typename T>
void	iter(T* array, size_t size, void (*f)(T &)) {
	for (size_t i = 0; i < size; i++) {
		f(array[i]);
	}
}

template<typename T>
void	iter(T const * array, size_t size, void (*f)(T const &)) {
	for (size_t i = 0; i < size; i++) {
		f(array[i]);
	}
}

#endif
