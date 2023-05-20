/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 20:41:00 by edelage           #+#    #+#             */
/*   Updated: 2023/05/20 20:41:00 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#ifndef HARL_HPP
# define HARL_HPP

# include <string>

class Harl {

public:
	Harl();

	void	complain(std::string level);

private:
	void	debug();
	void	info();
	void	warning();
	void	error();

};

#endif
