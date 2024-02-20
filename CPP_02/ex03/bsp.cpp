/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:31:35 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/02/20 14:13:37 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// funcao que verfica se os pontos p1 e p2 estao do mesmo lado da reta AB

bool compare_side (Fixed xP1,  Fixed yP1, Fixed xP2, Fixed yP2, Fixed xA, Fixed yA, Fixed xB, Fixed yB)
{
    if (xA == xB)
    {
        if (xA == xP2)
            return (false);
        if ((xP1 > xA) == (xP2 > xA))
            return (true);
        else
            return (false);
    }
    if ((yP1 > (((yB - yA) * xP1 + xB * yA - xA * yB) / (xB - xA))) == (yP2 > (((yB - yA) * xP2 + xB * yA - xA * yB) / (xB - xA))))
        return (true);
    else
        return (false);
}

bool	bsp( Point const a, Point const b, Point const c, Point const Point)
{
    if (compare_side(Point.getX(), Point.getY(), a.getX(), a.getY(), b.getX(), b.getY(), c.getX(), c.getY()))
        if (compare_side(Point.getX(), Point.getY(), b.getX(), b.getY(), a.getX(), a.getY(), c.getX(), c.getY()))
            if (compare_side(Point.getX(), Point.getY(), c.getX(), c.getY(), a.getX(), a.getY(), b.getX(), b.getY()))
              return (true);
    return (false);  
}