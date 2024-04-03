/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:43:46 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/04/03 18:06:00 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <string>
#include <iostream>

class AAnimal
{
    protected:
        std::string type;

    public:
        AAnimal(void);
        AAnimal(std::string name);
        AAnimal(const AAnimal &ct);
        virtual ~AAnimal(void);

        AAnimal & operator=(const AAnimal &ct);

        virtual void makeSound() const = 0;
        std::string getType() const;
};
#endif
