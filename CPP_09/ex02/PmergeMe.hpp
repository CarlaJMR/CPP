/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:43:46 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/06/19 15:17:00 by cjoao-me         ###   ########.fr       */
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
#include <algorithm>

class PmergeMe
{
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe & operator=(PmergeMe const & other);
        ~PmergeMe();

        void merge_insertion(char **input);
        
        class	InvalidArgsException : public std::exception
		{
			public:
				const char	*what() const throw();
		};
    
    private:
        std::vector<int> _vector;
		std::list<int>	 _list;
        void vector_merge_insertion();
        void vectorRecursiveSort(int size);
        void list_merge_insertion();
        void listRecursiveSort(int size);
        bool validate_args(char **input);
};

template <typename T>
void print_container(T & contain)
{
    int counter = 0;
    for (typename T::iterator it = contain.begin(); it != contain.end(); ++it)
    {
        if (counter == 100)
        {
            std::cout << "[...]";
            break;
        }
        std::cout << *it << " ";
        counter++;
    }
    std::cout << std::endl;
}

std::vector<long int> jacobsthalIndexSequence(int n);

#endif