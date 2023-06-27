/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 02:39:00 by edelage           #+#    #+#             */
/*   Updated: 2023/06/27 02:39:00 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <deque>

template <typename T>
class MutantStack: public std::stack<T> {

public:
	typedef typename std::deque<T>::iterator	iterator;
	MutantStack(): std::stack<T>() {};
	MutantStack(MutantStack const &other): std::stack<T>(other) {};
	~MutantStack() {};

	MutantStack &operator=(MutantStack const &other) {
		*this = other;
		return (*this);
	};

	iterator	end() {
		return (this->c.end());
	}

	iterator	begin() {
		return (this->c.begin());
	}

};

#endif