/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:43:46 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/05/31 18:37:15 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other)
{
    *this = other;
}

PmergeMe & PmergeMe::operator=(PmergeMe const & other)
{
    (void)other;
    return(*this);
}

PmergeMe::~PmergeMe() {}

void PmergeMe::merge_insertion(std::string *input)
{
    
    clock_t start;
    clock_t end;
    
    std::vector <int> args;
    
    if (!validate_args(input))
        throw PmergeMe::InvalidArgsException();
    
    //parsing ou o validate pode retornar um array que vai entrar diretamente na lista e no vetor
    
    std::vector<int> v(args.begin(), args.end());
    start = clock();
    vector_merge_insertion(&v);
    end = clock();
    clock_t vector_procTime = end - start;
    
    std::list<int> l(args.begin(), args.end());
    start = clock();
    list_merge_insertion(&l);
    end = clock();
    clock_t list_procTime = end - start;
    
    print_result(args, v, vector_procTime, list_procTime);
}

void PmergeMe::vector_merge_insertion(std::vector<int> *v)
{
    
}

void PmergeMe::list_merge_insertion(std::list<int> *l)
{
    
}

bool PmergeMe::validate_args(std::string *input)
{
    
}

void PmergeMe::print_result(std::vector<int> args, std::vector<int> v, clock_t vector_procTime, clock_t list_procTime)
{
    std::cout << "Before:  ";
    print_container(args);
    std::cout << "After:  ";
    print_container(v);
    std::cout << "Time to process a range of " << v.size() << " elements with std::vector: " << vector_procTime << std::endl;
    std::cout << "Time to process a range of " << v.size() << " elements with std::list: " << list_procTime << std::endl;
}


const char	*PmergeMe::InvalidArgsException::what() const throw()
{
	return ("Arguments should be different positive integers.");
}
