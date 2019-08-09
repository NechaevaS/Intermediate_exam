/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gold_gain.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 11:43:35 by snechaev          #+#    #+#             */
/*   Updated: 2019/08/09 12:17:16 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int compare(int n1, int n2, int n3)
{
	int res;
	if (n1 >= n2)
		res = n1;
	else
		res = n2;
	if (res < n3)
		res = n3;
	return (res);
}

int	gold_gain(int **mine, int n)
{
	int res = 0;
	int i = 1;
	int j;

	if (!mine)
		return (0);
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			if (j == 0)
				mine[j][i] = mine[j][i] + compare(0, mine[j][i - 1], mine[j + 1][i - 1]);
			else if (j == n - 1)
				mine[j][i] = mine[j][i] + compare(mine[j - 1][i - 1], mine[j][i - 1], 0);
			else
				mine[j][i] = mine[j][i] + compare(mine[j - 1][i - 1], mine[j][i - 1], mine[j + 1][i - 1]);

			j++;
		}
		i++;
	}
	i--;
	j = 0;
	while (j < n)
	{
		if (res < mine[j][i])
			res = mine[j][i];
		j++;
	}
	return (res);
}
