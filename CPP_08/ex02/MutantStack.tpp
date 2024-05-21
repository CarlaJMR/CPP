/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:42:06 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/05/21 11:58:05 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"


MutantStack::MutantStack(){}
MutantStack::~MutantStack(){}

class MutantStack : public std::stack<T>
{
  public:
    MutantStack();
    MutantStack(const MutantStack & other);
    MutantStack & operator=(const MutantStack & other);
    ~MutantStack();
  
  private:  
};

