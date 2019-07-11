/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pivot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 09:04:11 by exam              #+#    #+#             */
/*   Updated: 2019/07/09 09:24:38 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	find_summ(int *arr, int n)
{
	int i;
	int summ;

	i = 0;
	summ = 0;
	while(i < n)
	{
		summ = summ + arr[i];
		i++;
	}
	return (summ);
}

int	find_pivot(int *arr, int n)
{
	int i;
	int count;
	int summ;
	int piv;

	i = 0;
	count = 0;
	piv = -1;
	summ = find_summ(arr, n);
	if (n > 1)
	{
		while (i < n && piv == -1)
		{
			summ = summ - arr[i];
			if (count == summ)
				piv = i;
			else
				piv = -1;
			count = count + arr[i];
			i++;
		}
	}
	return (piv);
}
