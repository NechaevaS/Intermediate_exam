/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_subarray.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 16:36:34 by snechaev          #+#    #+#             */
/*   Updated: 2019/07/30 14:45:10 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

int count_len(char *str, int i)
{
	int len = 0;;
	int od = 0;
	int ev = 0;
	while(str[i])
	{
		if (!(str[i] % 2))
			od++;
		else
			ev++;
		if (od == ev)
			len = od + ev;
		i++;
	}
	return (len);
}

char	*longest_subarray(char *arr)
{
	int tot[strlen(arr)];
	char *res;
	int max = 0;
	int pos;
	int i = 0;
	int len;

	if (!arr)
		return (NULL);
	len = strlen(arr);
	while (i < len)
	{
		tot[i] = count_len(arr, i);
		if (tot[i] > max)
		{
			max = tot[i];
			pos = i;
		}
		i++;
	}
	res = (char *)malloc(sizeof(char) * max + 1);
	i = 0;
	while (i < max)
	{
		res[i] = arr[pos];
		i++;
		pos++;
	}
	res[i] = '\0';
	return (res);
}
