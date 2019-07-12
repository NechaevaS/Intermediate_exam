/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_of_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 14:28:38 by snechaev          #+#    #+#             */
/*   Updated: 2019/07/11 15:40:16 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check(int n)
{
	int count;

	count = 0;
	while (n)
	{
		if (n % 10 == 2)
			count++;
		n = n / 10;
	}
	return (count);
}

int	count_of_2(int n)
{
	int count = 0;

	if (n <= 1)
		return(0);
	while (n > 1)
	{
		count = count + check(n);
		n--;
	}
	return (count);
}