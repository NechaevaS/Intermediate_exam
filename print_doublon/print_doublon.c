/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_doublon.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 10:07:50 by exam              #+#    #+#             */
/*   Updated: 2019/07/23 14:08:40 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	print_doublon(int *a, int na, int *b, int nb)
{
	int i = 0;
	int j = 0;
	int f = 0;

	while (i < na && j < nb)
	{
		
		if (a[i] == b[j])
		{
			if (f == 0)
			{
				printf("%d", a[i]);
				f = 1;
		  	}
			else
				printf(" %d", a[i]);
			i++;
			j++;
		}
		else if (a[i] < b[j])
			i++;
		else
			j++;
	}
	printf("\n");
}