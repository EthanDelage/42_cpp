/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 00:37:00 by edelage           #+#    #+#             */
/*   Updated: 2023/05/21 00:37:00 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {

public:
	Fixed();
	Fixed(Fixed &copy);
	~Fixed();

	Fixed	&operator=(const Fixed &a);

	void	setRawBits(int const raw);
	int		getRawBits();

private:
	static const int	_nbFractionalBits = 8;
	int					_fixedPointValue;

};

#endif