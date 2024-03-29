/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:29:48 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/01/16 13:39:43 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
            for (j = 0; j < strlen(av[i]); j++)
                std::cout << (unsigned char)toupper(av[i][j]);
        std::cout << std::endl;
    }
}
