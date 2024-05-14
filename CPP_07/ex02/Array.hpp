/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:08:55 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/05/14 15:06:34 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>
#include <exception>

template <typename T>
class Array{
    private:
        size_t _len;
        T *arr;
        
    public:
        Array<T>();
        Array<T>(unsigned int n);
        Array<T>(Array const & other);
        Array & operator=(Array const & other);
        ~Array<T>();
        T &operator[](const size_t i);
        size_t size() const;
};

#include "Array.tpp"

#endif