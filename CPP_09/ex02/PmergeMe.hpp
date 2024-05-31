/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:43:46 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/05/31 18:37:21 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <vector>
#include <list>
#include <array>
#include <algorithm>

class PmergeMe
{
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe & operator=(PmergeMe const & other);
        ~PmergeMe();

        void merge_insertion(std::string *input);
        
        class	InvalidArgsException : public std::exception
		{
			public:
				const char	*what() const throw();
		};
    
    private:
        void vector_merge_insertion(std::vector<int> *v);
        void list_merge_insertion(std::list<int> *l);
        bool validate_args(std::string *input);
        void print_result(std::vector<int> args, std::vector<int> v, clock_t vector_procTime, clock_t list_procTime);
};

template <typename T>
void print_container(T & contain)
{
    for (typename T::iterator it = contain.begin(); it != contain.end(); ++it)
        std::cout << *it << " ";
    std::cout << '\n';
}

#endif