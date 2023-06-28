/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rpn.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:00:00 by edelage           #+#    #+#             */
/*   Updated: 2023/06/27 17:00:00 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <string>

typedef enum e_id {
	NUMBER,
	OPERATOR,
	SPACE,
	UNDEFINED
} t_id;

bool 	isValidInput(std::string input);
int		calculateRPN(std::string input);
t_id	getId(char c);

#endif