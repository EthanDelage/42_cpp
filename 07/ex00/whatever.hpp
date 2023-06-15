/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 21:26:00 by edelage           #+#    #+#             */
/*   Updated: 2023/06/15 21:26:00 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template<typename T>
T const	&max(T const &a, T const &b) {
	if (a > b)
		return (a);
	return (b);
}

template<typename T>
T const	&min(T const &a, T const &b) {
	if (a > b)
		return (b);
	return (a);
}

template<typename T>
void	swap(T &a, T &b) {
	T	tmp;

	tmp = a;
	a = b;
	b = tmp;
}

#endif
