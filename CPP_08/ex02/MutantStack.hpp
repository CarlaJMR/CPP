/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:42:06 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/05/31 12:42:52 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <algorithm>
#include <exception>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
  public:
    MutantStack();
    MutantStack(const MutantStack & other);
    MutantStack & operator=(const MutantStack & other);
    ~MutantStack();
    typedef	typename std::stack<T>::container_type::iterator iterator;
		iterator	begin();
		iterator	end();
  
};

#include "MutantStack.tpp"

#endif