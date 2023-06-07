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

# include <iostream>

class Fixed {

public:
	Fixed();
	Fixed(const int);
	Fixed(const float);
	Fixed(const Fixed &copy);
	~Fixed();

	Fixed				&operator=(const Fixed &a);

	void	setRawBits(int const raw);
	int		getRawBits() const;
	int		toInt() const;
	float	toFloat() const;

private:
	static const int	_nbFractionalBits = 8;
	int					_fixedPointValue;

};

std::ostream	&operator<<(std::ostream &os, const Fixed &a);

#endif