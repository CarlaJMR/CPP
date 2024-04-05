/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:44:09 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/04/05 15:29:14 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

extern AMateria *floorMateria[50];

class MateriaSource : public IMateriaSource
{
    private:
        AMateria *_learning[4];
        
    public:
        MateriaSource();
        MateriaSource(MateriaSource const & other);
        MateriaSource & operator=(MateriaSource const & other);
        ~MateriaSource();
        
        void learnMateria(AMateria*);
        AMateria* createMateria(std::string const & type);

       
};

void dropMateria(AMateria *m);
void cleanFloor(void);
        
#endif

