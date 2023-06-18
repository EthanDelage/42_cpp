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
# include <algorithm>

template<typename T>
int	easyfind(T const &container, int toFind) {
	if (std::find(container.begin(), container.end(), toFind) != container.end())
		return (toFind);
	throw std::exception();
}

#endif
