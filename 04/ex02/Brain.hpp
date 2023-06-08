/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 01:49:00 by edelage           #+#    #+#             */
/*   Updated: 2023/06/08 01:49:00 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>

# define NB_IDEAS	100

class Brain {

public:
	Brain();
	Brain(Brain const &other);
	~Brain();

	Brain &operator=(Brain const &other);

private:
	std::string	_ideas[NB_IDEAS];

};

#endif