/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 11:24:52 by snechaev          #+#    #+#             */
/*   Updated: 2019/07/12 12:43:37 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	equation(int n)
{
	int a;
	int b;
	int c;
	int t ;

	a = 0;
	while (a < 10 && ((a * 10) + a) <= n)
	{
		t = n - (a * 10 + a);
		c = t / 10;
		b = t % 10;
		if (b < 10 && c < 10)
			printf("A = %d, B = %d, C = %d\n", a, b, c);
		a++;
    }
}
