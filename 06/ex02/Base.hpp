/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:21:00 by edelage           #+#    #+#             */
/*   Updated: 2023/06/15 15:21:00 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#ifndef BASE_HPP
# define BASE_HPP

class Base {

public:
	virtual	~Base();

	static Base	*generate();
	static void	identify(Base *ptr);
	static void	identify(Base &ref);
};

#endif