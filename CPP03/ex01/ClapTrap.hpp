#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap
{
    private:
        std::string _name;
        int _hitpoints;
        int _energypoints;
        int _damage;

    public:
        ClapTrap(void);
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap &ct);
        ~ClapTrap(void);

        ClapTrap & operator=(const ClapTrap &ct);

        std::string getName(void) const;
        int getHitPoints(void) const;
        int getEnergyPoints(void) const;
        int getDamage(void) const;

        void setName(std::string name);
        void setHitPoints(int hp);
        void setEnergyPoints(int ep);
        void setDamage(int d);

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};
#endif