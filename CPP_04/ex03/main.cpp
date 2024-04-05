/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:44:09 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/04/05 16:35:48 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main(void)
{
    {
		std::cout << "\nSubject provided tests" << std::endl;
    	IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		me->use(2, *bob);
		delete bob;
		delete me;
		delete src;
	}

 	{
		std::cout << "\nLearn and create Materia tests" << std::endl;
    	IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Cure());
		src->learnMateria(new Cure());
		src->learnMateria(new Cure());
		src->learnMateria(new Cure());
		src->learnMateria(new Cure());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		tmp = src->createMateria("");
		me->equip(tmp);
		delete me;
		delete src;
	}

	{
		std::cout <<"\nUnequiped Materia leak tests" << std::endl;
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		me->unequip(0);
		me->unequip(1);
		me->unequip(2);
		me->unequip(6);
		delete me;
		delete src;
	}
	
	{
		std::cout << std::endl <<"\nMore Unequiped Materia tests" << std::endl;
		MateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		Character* Tiago = new Character("Tiago");
		AMateria* tmp;
		for (int i = 0; i < 52; i++)
		{
			tmp = src->createMateria("ice");
			Tiago->equip(tmp);
		}
		Character* TiagoEqual = new Character("Random");
		Tiago->use(0, *TiagoEqual);
		Tiago->use(1, *TiagoEqual);
		Tiago->use(2, *TiagoEqual);
		Tiago->use(3, *TiagoEqual);
		std::cout <<"\nDeep copy tests" << std::endl;
		*TiagoEqual = *Tiago;
		Character TiagoCopy (*Tiago);
		std::cout <<"Tiago Copy from copy constructor uses Materias" << std::endl;
		TiagoCopy.use(0, *Tiago);
		TiagoCopy.use(1, *Tiago);
		TiagoCopy.use(2, *Tiago);
		TiagoCopy.use(3, *Tiago);
		std::cout <<"Tiago Copy from assignment operator uses Materias" << std::endl;
		TiagoEqual->use(0, *Tiago);
		TiagoEqual->use(1, *Tiago);
		TiagoEqual->use(2, *Tiago);
		TiagoEqual->use(3, *Tiago);
		tmp = src->createMateria("cure");
		TiagoCopy.unequip(0);
		TiagoCopy.equip(tmp);
		tmp = src->createMateria("cure");
		TiagoEqual->unequip(1);
		TiagoEqual->equip(tmp);
		std::cout << "Checking first two slots atfer changes in copies" << std::endl;
		std::cout << "Original Tiago" << std::endl;
		Tiago->use(0, *TiagoEqual);
		Tiago->use(1, *TiagoEqual);
		std::cout << "Copy from copy constructor" << std::endl;
		TiagoCopy.use(0, *Tiago);
		TiagoCopy.use(1, *Tiago);
		std::cout << "Copy from assignment operator" << std::endl;
		TiagoEqual->use(0, *Tiago);
		TiagoEqual->use(1, *Tiago);
		delete Tiago;
		delete TiagoEqual;
		delete src;
	}
	cleanFloor();
    return 0;
}