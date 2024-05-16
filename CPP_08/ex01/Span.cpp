/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:42:06 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/05/16 18:14:04 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"


Span::Span(void): N(0) {}
  
Span::Span(int maxN): N(maxN) {}
  
Span::Span(const Span & other)
{
  *this = other;
}
  
Span::~Span() {}
  
Span & Span::operator=(const Span & other)
{
  if (_v.size()) {
    _v.clear();}
  N = other.N;
  _v = other._v;
  return (*this);
}

void Span::addNumber(int numb)
{
  (void)numb;
}


int Span::shortestSpan()
{
  return 0;
}

int Span::longestSpan()
{
  return 0;
}

