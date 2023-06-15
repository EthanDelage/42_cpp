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
		this->_array = NULL;
		this->_size = 0;
	};
	Array(unsigned int size) {
		this->_array = new T[size];
		this->_size = size;
		for (unsigned int i = 0; i < size; ++i) {
			this->_array[i] = T();
		}
	};
	Array(Array const &other) {
		*this = other;
	};
	~Array() {
		delete this->_array;
	};

	Array &operator=(Array const &other) {
		if (*this == other)
			return (*this);
		this->_array = new T[other._size];
		this->_size = other._size;
		for (unsigned int i = 0; i < this->_size; ++i) {
			this->_array[i] = other._array[i];
		}
		return (*this);
	};
	T	&operator[](unsigned int index) {
		if (index >= this->_size)
			throw std::exception();
		return (this->_array[index]);
	};

	unsigned int	size() const {
		return this->_size;
	};

private:
	T				*_array;
	unsigned int	_size;

};

#endif