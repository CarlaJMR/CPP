/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:42:06 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/05/21 12:29:53 by cjoao-me         ###   ########.fr       */
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
  if (_v.size() >= N)
    throw Span::FullContainerException();
  _v.push_back(numb);
}

void Span::addNumber(int numb, size_t range)
{
  if (_v.size() + range > N)
    throw Span::FullContainerException();
  _v.insert (_v.end(), range, numb);
}

int Span::shortestSpan()
{
  std::vector<int> dif;
  
  if (_v.size() <= 1)
    throw Span::NoExistentSpanException();
  
  std::sort (_v.begin(), _v.end());
  for (std::vector<int>::iterator it=_v.begin(); it != _v.end() -1 ; it++)
    dif.push_back(*(it + 1) - *it);
  return (*std::min_element(dif.begin(), dif.end()));
}

int Span::longestSpan()
{
  if (_v.size() <= 1)
    throw Span::NoExistentSpanException();
  return(*std::max_element(_v.begin(), _v.end()) - *std::min_element(_v.begin(), _v.end()));
}

const char	*Span::FullContainerException::what() const throw()
{
	return ("No space left in the container do add the amount of numbers requested!");
}

const char	*Span::NoExistentSpanException::what() const throw()
{
	return ("Not enough numbers to calculate the span.");
}

void Span::print()
{
  for (std::vector<int>::iterator it=_v.begin(); it!=_v.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
}
