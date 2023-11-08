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

#include <cstdlib>
# include <list>
# include <vector>

# define K 11

class PmergeMe {

public:
	PmergeMe();
	PmergeMe(int argc, char **argv);
	PmergeMe(PmergeMe const &other);
	~PmergeMe();

	PmergeMe &operator=(PmergeMe const &other);

	void	display();

private:
	std::vector<int>	_vector;
	std::list<int>	_list;

	int		parseArgument(char const *str);

	void	mergeInsertSortVector(std::vector<int> & vector);
	void	insertSortVector(std::vector<int> & vector);
	void	mergeInsertSortList(std::list<int> & list);
	void	insertSortList(std::list<int> & list);
};

#endif