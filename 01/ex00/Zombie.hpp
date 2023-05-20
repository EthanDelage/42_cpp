/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 12:59:00 by edelage           #+#    #+#             */
/*   Updated: 2023/05/20 12:59:00 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie {

private:
	std::string	_name;

public:
	Zombie(std::string name);
	~Zombie();

	void			announce();

};

Zombie	*newZombie(std::string name);
void		randomChump(std::string name);

#endif
