/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:42:06 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/05/16 17:02:53 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <exception>

class	notFoundException : public std::exception{
	public:
		const char	*what() const throw() {return("Value not found");}
};

template <typename T>
typename T::iterator easyfind(T & contain, int n)
{
    typename T::iterator it = find(contain.begin(), contain.end(), n);
    if (it == contain.end())
        throw notFoundException();
    return (it);
}
#endif