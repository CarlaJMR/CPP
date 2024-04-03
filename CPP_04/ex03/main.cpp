/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carla <carla@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:44:09 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/04/01 11:52:34 by carla            ###   ########.fr       */
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
		Character* Rambo = new Character("Rambo");
		Character* Batman = new Character("Batman");
		Rambo->use(0, *Batman);
		AMateria* tmp;
		tmp = src->createMateria("ice");
		Rambo->equip(tmp);
		tmp = src->createMateria("cure");
		Rambo->equip(tmp);
		tmp = src->createMateria("ice");
		Rambo->equip(tmp);
		tmp = src->createMateria("cure");
		Rambo->equip(tmp);
		tmp = src->createMateria("ice");
		Rambo->equip(tmp);
		delete tmp;
		Rambo->use(0, *Batman);
		// for (int i = 0; i < 110; i++)
		// {
		// 	Rambo->unequip(0);
		// 	tmp = src->createMateria("ice");
		// 	Rambo->equip(tmp);
		// }
		Rambo->unequip(0);
		Rambo->unequip(1);
		Rambo->unequip(1);
		//show_dropped();
		Rambo->use(0, *Batman);
		std::cout << "\nDeep copy tests" << std::endl;
		MateriaSource* copy = new MateriaSource();
		*copy = *src;
		copy->learnMateria(new Cure());
		copy->learnMateria(new Ice());
        copy->learnMateria(new Cure());
		src->learnMateria(new Cure());
		Character* RamClone = new Character("Random");
		*RamClone = *Rambo;
		tmp = copy->createMateria("cure");
		RamClone->equip(tmp);
		tmp = copy->createMateria("ice");
		RamClone->equip(tmp);
		RamClone->use(0, *Rambo);
		RamClone->use(1, *Rambo);
		RamClone->use(2, *Rambo);
		RamClone->use(3, *Rambo);
		std::cout << "\nOriginal Rambo should be unchanged" << std::endl;
		Rambo->use(0, *RamClone);
		Rambo->use(3, *RamClone);
		delete Rambo;
		delete Batman;
		delete src;
		delete RamClone;
		delete copy;
		//clearDropped();
	}
   /* std::cout << std::endl;
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
    me->equip(tmp);
    me->equip(tmp);
    me->equip(tmp);
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    me->unequip(0);
    me->unequip(0);
    me->unequip(6);
    delete bob;
    delete me;
    delete src;
    }*/

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
    
/*std::cout << "\nMy tests" << std::endl;
	{
		MateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		Character* Rambo = new Character("Rambo");
		Character* Batman = new Character("Batman");
		Rambo->use(0, *Batman);
		AMateria* tmp;
		tmp = src->createMateria("ice");
		Rambo->equip(tmp);
		tmp = src->createMateria("cure");
		Rambo->equip(tmp);
		tmp = src->createMateria("ice");
		Rambo->equip(tmp);
		tmp = src->createMateria("cure");
		Rambo->equip(tmp);
		tmp = src->createMateria("ice");
		Rambo->equip(tmp);
		delete tmp;
		Rambo->use(0, *Batman);
		// for (int i = 0; i < 110; i++)
		// {
		// 	Rambo->unequip(0);
		// 	tmp = src->createMateria("ice");
		// 	Rambo->equip(tmp);
		// }
		Rambo->unequip(0);
		Rambo->unequip(1);
		Rambo->unequip(1);
		show_dropped();
		Rambo->use(0, *Batman);
		std::cout << "\nDeep copy tests" << std::endl;
		MateriaSource* copy = new MateriaSource();
		*copy = *src;
		copy->learnMateria(new Cure());
		copy->learnMateria(new Cure());
		copy->learnMateria(new Ice());
		src->learnMateria(new Cure());
		Character* RamClone = new Character("Random");
		*RamClone = *Rambo;
		tmp = copy->createMateria("cure");
		RamClone->equip(tmp);
		tmp = copy->createMateria("ice");
		RamClone->equip(tmp);
		RamClone->use(0, *Rambo);
		RamClone->use(1, *Rambo);
		RamClone->use(2, *Rambo);
		RamClone->use(3, *Rambo);
		std::cout << "\nOriginal Rambo should be unchanged" << std::endl;
		Rambo->use(0, *RamClone);
		Rambo->use(3, *RamClone);
		delete Rambo;
		delete Batman;
		delete src;
		delete RamClone;
		delete copy;
		clearDropped();
	}*/
    
    return 0;
}