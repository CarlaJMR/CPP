#include <iostream>
#include <cstring>

int     main(int ac, char **av)
{
    int i, j;

    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" <<std::endl;
    else
    {
        for (i=1; i < ac; i++)
            std::cout << toupper(*av[i]);
        std::cout << std::endl;
    }
}