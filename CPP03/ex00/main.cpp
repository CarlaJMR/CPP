#include "ClapTrap.hpp"

int main( void )
{
	ClapTrap A("Aniceto");
	ClapTrap B("Blimundo");
    ClapTrap C("Cesaltino");

	A.attack("enemy");
	A.takeDamage(10);
    A.attack("ghost");
    A.beRepaired(5);
    B.beRepaired(5);
	B.beRepaired(5);
    C.takeDamage(7);
    for (int i = 1; i < 13; i++){
        C.attack("anyone");}
	return 0;
}