/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShallowCat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:43:46 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/03/04 19:07:59 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHALLOW_CAT_HPP
#define SHALLOW_CAT_HPP

#include <string>
#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class ShallowCat: public Animal
{
    private:
        Brain *_brain;

    public:
        ShallowCat(void);
        ShallowCat(const ShallowCat &ct);
        ~ShallowCat(void);

        ShallowCat & operator=(const ShallowCat &ct);

        void makeSound() const;
        Brain *getBrain(void) const;
};
#endif
