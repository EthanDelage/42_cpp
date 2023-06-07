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
	Fixed				&operator++();
	Fixed				&operator--();
	Fixed				operator++(int);
	Fixed				operator--(int);

	void		setRawBits(int const raw);
	int			getRawBits() const;
	static int	getNbFractionalBits();
	int			toInt() const;
	float		toFloat() const;

	static const Fixed	&min(const Fixed &a, const Fixed &b);
	static const Fixed	&max(const Fixed &a, const Fixed &b);
	static Fixed	min(Fixed &a, Fixed &b);
	static Fixed	max(Fixed &a, Fixed &b);

private:
	static const int	_nbFractionalBits = 8;
	int					_fixedPointValue;

};

Fixed			operator+(const Fixed &a, const Fixed &b);
Fixed			operator-(const Fixed &a, const Fixed &b);
Fixed			operator*(const Fixed &a, const Fixed &b);
Fixed			operator/(const Fixed &a, const Fixed &b);
bool			operator>(const Fixed &a, const Fixed &b);
bool			operator<(const Fixed &a, const Fixed &b);
bool			operator>=(const Fixed &a, const Fixed &b);
bool			operator<=(const Fixed &a, const Fixed &b);
bool			operator==(const Fixed &a, const Fixed &b);
bool			operator!=(const Fixed &a, const Fixed &b);
std::ostream	&operator<<(std::ostream &os, const Fixed &a);

#endif