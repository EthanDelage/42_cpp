/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rpn.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:00:00 by edelage           #+#    #+#             */
/*   Updated: 2023/06/27 17:00:00 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "RPN.hpp"
#include <iostream>

static int	do_op(std::stack<int> &numberStack, char op);

bool isValidInput(std::string input) {
	t_id	id;

	id = getId(input[0]);
	for (int i = 1; input[i]; ++i) {
		if (id == UNDEFINED)
			return (false);
		else if (id == getId(input[i]) && id != SPACE)
			return (false);
		id = getId(input[i]);
	}
	return (true);
}

int	calculateRPN(std::string input) {
	std::stack<int>		numberStack;

	for (int i = 0; input[i]; ++i) {
		if (getId(input[i]) == NUMBER)
			numberStack.push(input[i] - '0');
		else if (getId(input[i]) == OPERATOR)
			numberStack.push(do_op(numberStack, input[i]));
	}
	if (numberStack.size() != 1)
		throw std::runtime_error("Error");
	return (numberStack.top());
}

static int	do_op(std::stack<int> &numberStack, char op) {
	int result;

	if (numberStack.size() < 2)
		throw std::runtime_error("Error");
	result = numberStack.top();
	numberStack.pop();
	if (op == '+')
		result += numberStack.top();
	else if (op == '-')
		result = numberStack.top() - result;
	else if (op == '*')
		result *= numberStack.top();
	else if (op == '/') {
		if (result == 0)
			throw std::runtime_error("Error");
		result = numberStack.top() / result;
	}
	numberStack.pop();
	return (result);
}

t_id	getId(char c) {
	if (isdigit(c))
		return (NUMBER);
	else if (c == ' ')
		return (SPACE);
	else if (c == '+' || c == '-' || c == '*' || c == '/')
		return (OPERATOR);
	return (UNDEFINED);
}
