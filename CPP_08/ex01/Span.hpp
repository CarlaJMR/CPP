/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:42:06 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/05/16 18:13:03 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>

class Span
{
  public:
    Span();
    Span(int Nmax);
    Span(const Span & other);
    ~Span();
    Span & operator=(const Span & other);
    
    void addNumber(int numb);
    int shortestSpan();
    int longestSpan();
  
  private:
    std::vector<int> _v;
    unsigned int N;
};

#endif