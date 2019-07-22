/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   volume_histogram.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 11:35:11 by snechaev          #+#    #+#             */
/*   Updated: 2019/07/22 14:00:23 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// int		finde_max(int *arr, int size, int *curr, int *pos)
// {
// 	int i = 0;
// 	int max = 0;

// 	while (i < size)
// 	{
// 		if (arr[i] >= *curr)
// 		{
// 			max = arr[i];
// 			*pos = i;
// 		}
// 		i++;
// 	}
// 	return (max);
// }

// int count_dots(int *arr, int size, int *max)
// {
// 	int count = 0;
// 	int i = 0;
// 	while(i < size)
// 	{
// 		if (!arr[i])
// 			count = count + *max;
// 		else
// 			count = count + *max - arr[i];
// 		i++;
// 	}
// 	return (count);
// }

// int		volume_histogram(int *histogram, int size)
// {
// 	int max;
// 	int curr;
// 	int pos = 0;
// 	int count = 0;
// 	int i = 0;
// 	int p_size = size;
// 	while (i < size)
// 	{
// 		if (histogram[i])
// 		{
// 			curr = histogram[i];
// 			max = finde_max(&histogram[i], size - i - 1, &curr, &pos);
// 			if (!max)
// 			if (max > curr)
// 				max = curr;
// 			p_size = pos;
// 			count = count + count_dots(&histogram[i], size, &max);
// 			i = i + pos;
// 		}
// 		i++;
// 	}
// 	return (count);
//}

int		volume_histogram(int *histogram, int size)
{
	int i;
	int h;
	int w;
	int lev_left;
	int lev_right;

	i = 0;
	w = 0;
	lev_left = 0;
	lev_right = 0;
	h = size - 1;
	while (i <= h)
	{
		if (histogram[i] < histogram[h])
		{
			if (histogram[i] > lev_left)
				lev_left = histogram[i];
			else
				w = w + (lev_left - histogram[i]);
			i++;
		}
		else
		{
			if (histogram[h] > lev_right)
				lev_right = histogram[h];
			else
				w = w + (lev_right - histogram[h]);
			h--;
		}
	}
	return (w);
}