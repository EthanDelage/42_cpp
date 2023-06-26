/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 21:59:00 by edelage           #+#    #+#             */
/*   Updated: 2023/06/15 21:59:00 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>
# include <iostream>

template<typename T>
class Array {

public:
	Array() {
		_array = NULL;
		_size = 0;
	};

	Array(unsigned int size) {
		_array = new T[size];
		_size = size;
		for (unsigned int i = 0; i < size; ++i) {
			_array[i] = T();
		}
	};

	Array(Array const &other) {
		_array = NULL;
		*this = other;
	};

	~Array() {
		delete[] _array;
	};

	Array &operator=(Array const &other) {
		if (this == &other)
			return (*this);
		if (_array)
			delete[] _array;
		_array = new T[other._size];
		_size = other._size;
		for (unsigned int i = 0; i < _size; ++i) {
			_array[i] = other._array[i];
		}
		return (*this);
	};

	T	&operator[](unsigned int index) {
		if (index >= _size)

			throw std::exception();
		return (_array[index]);
	};

	unsigned int	size() const {
		return _size;
	};

private:
	T				*_array;
	unsigned int	_size;

};

#endif