/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 09:42:14 by exam              #+#    #+#             */
/*   Updated: 2019/07/17 12:30:11 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flood_fill.h"

void  fill(char **tab, t_point size, t_point begin, char c)
{
    int x;
    int y;
    t_point new;

    y = begin.y;
    x = begin.x;
    if (x >= size.x || y >= size.y || x < 0 || y < 0)
        return ;
	if(tab[y][x] != c)
		return ;
    tab[y][x] = 'F';

	new.x = x + 1;
	new.y = y;
	fill(tab, size, new, c);

	new.x = x - 1;
	new.y = y;
	fill(tab, size, new, c);

	new.x = x;
	new.y = y + 1;
	fill(tab, size, new, c);

	new.x = x;
	new.y = y - 1;
	fill(tab, size, new, c);
}

 void  flood_fill(char **tab, t_point size, t_point begin)
{
	char symb;

	symb = tab[begin.y][begin.x];
	fill(tab, size, begin, symb);
}
