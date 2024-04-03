/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:44:09 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/04/03 15:03:30 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main(void)
{
    {
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
    //me->unequip(1);
    delete bob;
    delete me;
    delete src;
    }
    std::cout <<std::endl;
	{
	MateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	Character* Tiago = new Character("Tiago");
	Character* Sofia = new Character("Sofia");
	Tiago->use(0, *Sofia);
	AMateria* tmp;
	tmp = src->createMateria("ice");
	Tiago->equip(tmp);
	tmp = src->createMateria("cure");
	Tiago->equip(tmp);
	tmp = src->createMateria("ice");
	Tiago->equip(tmp);
	tmp = src->createMateria("cure");
	Tiago->equip(tmp);
	tmp = src->createMateria("ice");
	Tiago->equip(tmp);
	delete tmp;
	Tiago->use(0, *Sofia);
	// for (int i = 0; i < 110; i++)
	// {
	// 	Tiago->unequip(0);
	// 	tmp = src->createMateria("ice");
	// 	Tiago->equip(tmp);
	// }
	Tiago->unequip(0);
	Tiago->unequip(1);
	Tiago->unequip(1);
	//show_dropped();
	Tiago->use(0, *Sofia);
	std::cout << "\nDeep copy tests" << std::endl;
	MateriaSource* copy = new MateriaSource();
	*copy = *src;
	copy->learnMateria(new Cure());
	copy->learnMateria(new Ice());
	copy->learnMateria(new Cure());
	src->learnMateria(new Cure());
	Character* TiagoCopy = new Character("Random");
	*TiagoCopy = *Tiago;
	tmp = copy->createMateria("cure");
	TiagoCopy->equip(tmp);
	tmp = copy->createMateria("ice");
	TiagoCopy->equip(tmp);
	TiagoCopy->use(0, *Tiago);
	TiagoCopy->use(1, *Tiago);
	TiagoCopy->use(2, *Tiago);
	TiagoCopy->use(3, *Tiago);
	std::cout << "\nOriginal Tiago should be unchanged" << std::endl;
	Tiago->use(0, *TiagoCopy);
	Tiago->use(3, *TiagoCopy);
	delete Tiago;
	delete Sofia;
	delete src;
	delete TiagoCopy;
	delete copy;

	/*IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    me->equip(tmp);
    me->equip(tmp);
    me->equip(tmp);
    me->equip(tmp);
    ICharacter* bob = new Character("bob");
    ICharacter* Mar = new Character("Marcell");
    me->use(0, *bob);
    me->use(1, *bob);
    Mar->unequip(3);
    Mar->unequip(1);
    Mar->use(0, *bob);
    Mar->use(1, *bob);
    *Mar = *me;
    me->use(0, *Mar);
    me->use(1, *Mar);
    Mar->use(0, *me);
    Mar->use(1, *me);
    tmp->deleteGroundItems();
    delete bob;
    delete me;
    delete Mar;
    delete src;*/
	//clearDropped();
	}
}