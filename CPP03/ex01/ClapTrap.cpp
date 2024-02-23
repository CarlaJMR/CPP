

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void): _hitpoints (10), _energypoints (10), _damage (0)
{
    std::cout << "Default ClapTrap constructor called" << std::endl;
    return;
}

ClapTrap::ClapTrap(std::string name): _name (name), _hitpoints (10), _energypoints (10), _damage (0)
{
    std::cout << "ClapTrap constructor called for " << name << std::endl;
    return;
}

ClapTrap::ClapTrap(const ClapTrap &ct)
{
    *this = ct;
    std::cout << "Copy ClapTrap constructor called for " << this->_name <<std::endl;
    return;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destructor called" << std::endl;
    return;
}

ClapTrap & ClapTrap::operator=(const ClapTrap &ct)
{
    if (this != &ct)
    {
        this->_name = ct.getName();
        this->_hitpoints = ct.getHitPoints();
        this->_energypoints = ct.getEnergyPoints();
        this->_damage = ct.getDamage();
    }
    return(*this);    
}


std::string ClapTrap::getName(void) const
{
    return(this->_name);
}

int ClapTrap::getHitPoints(void) const
{
    return(this->_hitpoints);
}

int ClapTrap::getEnergyPoints(void) const
{
    return(this->_energypoints);
}

int ClapTrap::getDamage(void) const
{
    return(this->_damage);
}

void ClapTrap::setName(std::string name)
{
    this->_name = name;
}

void ClapTrap::setHitPoints(int hp)
{
    this->_hitpoints = hp;
}

void ClapTrap::setEnergyPoints(int ep)
{
    this->_energypoints = ep;
}

void ClapTrap::setDamage(int d)
{
    this->_damage = d;
}

void ClapTrap::attack(const std::string& target)
{

}

void ClapTrap::takeDamage(unsigned int amount)
{

}

void ClapTrap::beRepaired(unsigned int amount)
{

}