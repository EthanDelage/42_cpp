/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:26:00 by edelage           #+#    #+#             */
/*   Updated: 2023/07/01 15:26:00 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <list>
# include <deque>

class PmergeMe {

public:
	PmergeMe();
	PmergeMe(int argc, char **argv);
	PmergeMe(PmergeMe const &other);
	~PmergeMe();

	PmergeMe &operator=(PmergeMe const &other);

private:
	std::list<int>	_list;
	std::deque<int>	_deque;

	int	parseArgument(char const *str);

};

#endif