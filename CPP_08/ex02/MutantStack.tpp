/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:42:06 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/05/31 12:28:02 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TPP
# define MUTANTSTACK_TPP

template <typename T>
MutantStack<T>::MutantStack(){}

template <typename T>
MutantStack<T>::~MutantStack(){}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack & other)
{
  *this = other;
}

template <typename T>
MutantStack<T> & MutantStack<T>::operator=(const MutantStack & other)
{
  if ( *this != other )
				std::stack<T>::operator=(other);
  return ( *this );
  
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() 
{ 
  return this->c.begin(); 
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() 
{ 
  return this->c.end();
}

#endif
