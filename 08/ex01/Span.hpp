/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 08:48:00 by edelage           #+#    #+#             */
/*   Updated: 2023/06/17 08:48:00 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <iostream>

class Span {

public:
	Span();
	Span(unsigned int size);
	Span(Span const &other);
	~Span();

	Span &operator=(Span const &other);

	void			addNumber(int number);

	template<typename T>
	void			addMultipleNumber(T	start, T end) {
		try {
			while (start != end) {
				addNumber(*start);
				++start;
			}
		} catch (std::exception const &e) {
			throw std::runtime_error(e.what());
		}
	}
	void			displaySpan();
	int 			shortestSpan();
	int 			longestSpan();
	unsigned int	getSize();
	unsigned int	getNbElem();

private:
	std::vector<int>	_span;
	unsigned int		_size;

};

#endif