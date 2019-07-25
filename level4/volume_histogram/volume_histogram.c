/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   volume_histogram.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 11:35:11 by snechaev          #+#    #+#             */
/*   Updated: 2019/07/22 14:19:12 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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