/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gold_gain.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 16:08:47 by snechaev          #+#    #+#             */
/*   Updated: 2019/07/17 17:27:51 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void zero_arr(int **arr, int h, int w)
{
	int i = 0;
	int j = 0;

	while(i < h)
	{
		j = 0;
		while(j < w)
		{
			arr[i][j] = 0;
			j++;
		}
		i++;
	}
}

int	**create_arr(int n)
{
	int	**arr;
	int i = 0;
	int h;
	int w;

	w = n;
	h = n + 2;
	arr = (int **)malloc(sizeof(int *) * h);
	while(i < n + 2)
	{
		arr[i] = (int *)malloc(sizeof(int) * w);
		i++;
	}
	zero_arr(arr, h, w);
	return (arr);
}

void free_arr(int **arr, int n)
{
	int i = 0;
	while(i < n + 2)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int compare3(int a, int b, int c)
{
	int res = 0;
	
	if (a > b)
		res = a;
	else
		res = b;
	if (res > c)
		return (res);
	else
		return (res = c);	
}

int	gold_gain(int **mine, int n)
{
	int res = 0;
	int i;
	int j;
	int **arr;

	if (!mine)
		return (0);
	arr = create_arr(n);
	i = 0;
	while(i < n)
	{
		arr[i +1][0] = mine[i][0];
		i++;
	}
	j = 1;
	while(j < n)
	{
		i = 1;
		while(i <= n)
		{
			arr[i][j] = mine[i - 1][j] + compare3(arr[i-1][j-1], arr[i][j-1], arr[i + 1][j - 1]);
			i++;
		}
		j++;
	}
	i = 1;
	j--;
	while(i <= n)
	{
		if (arr[i][j] > res)
			res = arr[i][j];
		i++;
	}
	free_arr(arr, n);
	return (res);
}