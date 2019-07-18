/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_alpha.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 11:20:13 by snechaev          #+#    #+#             */
/*   Updated: 2019/07/17 13:06:42 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_tolower(char *str)
{
	int i = 0;
	while(str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		str[i] = str[i] + 32;
		i++;
	}
}
void	zero_arr(int *arr)
{
	int i = 0;
	while (i < 26)
	{
		arr[i] = 0;
		i++;
	}
}
int	is_emp_arr(int *arr)
{
	int i = 0;
	while (i < 26)
	{
		if(arr[i] != 0)
			return (0);
		i++;
	}
	return (1);
}
void	fill_arr(char *str, int *arr)
{
	int i;
	int	pos;

	i = 0;
	while(str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			pos = str[i] - 'a';
			arr[pos] = arr[pos] + 1;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int arr[26];
	char *str;
	int i = 0;
	int	pos;

	str = argv[1];
	if(argc == 2)
	{
		ft_tolower(str);
		zero_arr(arr);
		fill_arr(str, arr);
		while (str[i] != '\0')
		{
			if (str[i] >= 'a' && str[i] <= 'z')
			{
				pos = str[i] - 'a';
				if(arr[pos] != 0)
				{
					printf("%d%c", arr[pos], pos + 'a');
					arr[pos] = 0;
					if(is_emp_arr(arr) == 0)
					printf(", ");
				}
			}
			i++;
		}
	}
	printf("\n");
	return (0);
}