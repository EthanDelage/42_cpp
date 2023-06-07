/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:51:00 by edelage           #+#    #+#             */
/*   Updated: 2023/06/07 19:51:00 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>

class WrongAnimal {

public:
	WrongAnimal();
	WrongAnimal(WrongAnimal const &other);
	virtual ~WrongAnimal();

	WrongAnimal &operator=(WrongAnimal const &other);

	std::string		getType() const;
	virtual void	makeSound() const;

protected:
	std::string _type;

};

#endif