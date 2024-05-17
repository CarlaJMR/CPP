/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:08:55 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/05/17 14:19:08 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

template <typename T>
Array<T>::Array(): _len(0), arr(0)
{
    return;
}

template <typename T>
Array<T>::Array(unsigned int n): _len(n)
{
    arr = new T[n];
    return;
}

template <typename T>
Array<T>::~Array()
{
    if (arr)
        delete [] arr;
    return;
}

template <typename T>
Array<T>::Array(Array const & other): _len(other._len)
{
    arr = new T[_len];
    for(size_t i = 0; i < _len; i++)
        arr[i] = other.arr[i];
    return;
}

template <typename T>
Array<T> & Array<T>::operator=(Array const & other)
{
    if (_len != other._len)
	{
		if (arr)
			delete [] arr;
		arr = new T[other._len];
		_len = other._len;
	}
	for (size_t i = 0; i < _len; i++)
		arr[i] = other.arr[i];
	return (*this);
}

template <typename T>
T & Array<T>::operator[](const size_t i) const
{
	if (i >= _len)
		throw std::out_of_range("Index is out of range");
	return (arr[i]);
}


template <typename T>
size_t Array<T>::size(void) const
{
	return (_len);
}

#endif
