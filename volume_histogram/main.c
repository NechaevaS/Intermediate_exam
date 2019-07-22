/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 13:01:30 by snechaev          #+#    #+#             */
/*   Updated: 2019/07/22 13:21:35 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int    volume_histogram(int *histogram, int size);

int main()
{
	int res = 0;
	int	histogram1[] = {1, 0, 2, 0, 2};
	int	size1 = 5;

	int	histogram2[] = {0, 0, 4, 0, 0, 6, 0, 0, 3, 0, 5, 0, 1, 0, 0, 0};
	int	size2 = 16;
	res = volume_histogram(histogram1, size1);
	printf("test 1 %d\n", res);
	res = volume_histogram(histogram2, size2);
	printf("test 2 %d\n", res);
}