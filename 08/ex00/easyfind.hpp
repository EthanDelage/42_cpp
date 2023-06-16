/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 21:45:00 by edelage           #+#    #+#             */
/*   Updated: 2023/06/16 21:45:00 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <exception>

template<typename T>
int	easyfind(T const &container, int toFind) {
	for (typename T::const_iterator it = container.begin(); it != container.end(); ++it) {
		if (*it == toFind)
			return (toFind);
	}
	throw std::exception();
}

#endif
