/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:43:46 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/06/19 15:36:37 by cjoao-me         ###   ########.fr       */
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
    if (this != &other)
	{
		this->_vector = other._vector;
		this->_list = other._list;
	}
	return (*this);
}

PmergeMe::~PmergeMe() {}

void PmergeMe::merge_insertion(char **input)
{
    clock_t start;
    clock_t end;
    
    if (!validate_args(input))
        throw PmergeMe::InvalidArgsException();
    
    _list.insert(_list.begin(), _vector.begin(), _vector.end());
    
    start = clock();
    vector_merge_insertion();
    end = clock();
    float vector_procTime = static_cast<float>(end - start) / CLOCKS_PER_SEC * 1000.0;
    
    start = clock();
    list_merge_insertion();
    end = clock();
    float list_procTime = static_cast<float>(end - start)/ CLOCKS_PER_SEC * 1000.0;
    
    std::cout << "After:  ";
    print_container(_list);
    std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector-> " << vector_procTime << " ms" << std::endl;
    std::cout << "Time to process a range of " << _list.size() << " elements with std::list-> " << list_procTime << " ms" << std::endl;
}

void PmergeMe::vector_merge_insertion()
{
    int straggler = 0;
    std::vector<int> pend;

    if (_vector.size() % 2)
    {
        straggler = _vector.back();
        _vector.pop_back();
    }
    for (int i = 0; i < static_cast<int>(_vector.size()); i += 2)
    {
        if (_vector[i] > _vector[i + 1])
            std::swap(_vector[i], _vector[i + 1]);
    }
    int size = _vector.size();
    if (size > 2)
    {
        vectorRecursiveSort(size - 1);
        for (int i = 2; i < size; i += 2)
            pend.push_back(_vector[i]);
        for (int i = 0; i < size/2 - 1; i++)
            _vector.erase(_vector.end() - 2 - i);
        std::vector<long int> jacob = jacobsthalIndexSequence(pend.size());
        std::vector<int>::iterator b_it;
	    for (size_t i = 0; i < jacob.size(); i++) 
        {
		    b_it = _vector.begin();
		    while (*b_it < pend[jacob[i]]){
			    b_it++;}
		    _vector.insert(b_it, pend[jacob[i]]);
	    }
    }
    if (straggler)
    {
        std::vector<int>::iterator it = std::lower_bound(_vector.begin(), _vector.end(), straggler);
	    _vector.insert(it, straggler);
    }
}

void	PmergeMe::vectorRecursiveSort(int size) 
{
	if (size == 1)
		return ;
	
	for (int i = 1; i < size; i += 2) 
    {
		if ( _vector[i] > _vector[size]) 
        {
			std::swap(_vector[i], _vector[size]);
            std::swap(_vector[i - 1], _vector[size - 1]);
		}
	}
	vectorRecursiveSort(size - 2);
}

void PmergeMe::list_merge_insertion()
{
    int straggler = 0;
    std::list<int> pend;

    if (_list.size() % 2)
    {
        straggler = _list.back();
        _list.pop_back();
    }
    std::list<int>::iterator next_it = ++_list.begin();
    for (std::list<int>::iterator it = _list.begin(); it != _list.end(); advance(it, 2))
    {
        if (*it > *(next_it))
            std::iter_swap(it, next_it);
        advance(next_it, 2);
    }
    int size = _list.size();
    if (size > 2)
    {
        listRecursiveSort(size - 1);
        for (std::list<int>::iterator it = ++(++_list.begin()); it != _list.end(); advance(it, 2))
            pend.push_back(*it);
        for (std::list<int>::iterator it = pend.begin(); it != pend.end(); it++)
            _list.remove(*it);
        std::vector<long int> jacob = jacobsthalIndexSequence(pend.size());
        std::list<int>::iterator main_it;
        std::list<int>::iterator pend_it;
	    for (size_t i = 0; i < jacob.size(); i++) 
        {
		    main_it = _list.begin();
            pend_it = pend.begin();
            advance(pend_it, jacob[i]);
		    while (*main_it < *pend_it){
			    main_it++;}
		    _list.insert(main_it, *pend_it);
	    }
    }
    if (straggler)
    {
        std::list<int>::iterator it = std::lower_bound(_list.begin(), _list.end(), straggler);
	    _list.insert(it, straggler);
    }
}

void PmergeMe::listRecursiveSort(int size)
{
    if (size == 1)
		return ;
    std::list<int>::iterator it =++_list.begin();
    std::list<int>::iterator it_size = _list.begin();
    advance(it_size, size);
	for (int i = 1; i < size; i += 2) 
    {
        if (*it > *it_size)
        {
            std::iter_swap(it, it_size);
            std::swap(*(--it), *(--it_size));
            it++;
            it_size++;
        }
        advance(it, 2);
	}
	listRecursiveSort(size - 2);
}

bool PmergeMe::validate_args(char **input)
{
    long int number;
	
	for (int i = 1; input[i]; i++)
	{
        for (int j = 0; input[i][j]; j++)
			if (!isdigit(input[i][j]))
				return (false);
        number = atoi(input[i]);
        if (number <= 0 || number > 2147483647)
            return (false);
        std::vector<int>::iterator it = find(_vector.begin(), _vector.end(), number);
        if (it != _vector.end())
            return (false);
		_vector.push_back(number);
	}
	std::cout << "Before:  ";
    print_container(_vector);
	return (true);
}

std::vector<long int> jacobsthalIndexSequence(int n)
{
    long jacobsthal[] = {-1, 1, 3, 9, 19, 41, 83, 169, 339, 681, 
        1363, 2729, 5459, 10921, 21843, 43689, 87379, 174761, 349523, 699049, 
        1398099, 2796201, 5592403, 11184809, 22369619, 44739241, 89478483,
        178956969, 357913939, 715827881, 1431655763, 2863311529, 5726623059, 11453246121};
    /*{0, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 
	1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525, 699051, 
	1398101, 2796203, 5592405, 11184811, 22369621, 44739243, 89478485, 
	178956971, 357913941, 715827883, 1431655765, 2863311531, 5726623061, 11453246123};*/
    
    std::vector<long int> sequence;
	int	i = 0;
	long temp = 0;

	while (n > jacobsthal[i])
		i++;
	for (int j = 0; j < i; j++) {
		temp = jacobsthal[j + 1];
		if (temp >= n)
			temp = n - 1;
		while (temp > jacobsthal[j]) {
			sequence.push_back(temp);
			temp--;
		}
	}
    return (sequence);
}

const char	*PmergeMe::InvalidArgsException::what() const throw()
{
	return ("Arguments should be different positive numbers in the range of integers.");
}
