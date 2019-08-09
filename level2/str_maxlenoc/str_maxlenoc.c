/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_maxlenoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 14:02:34 by snechaev          #+#    #+#             */
/*   Updated: 2019/08/09 12:59:51 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int str_len(char *str)
{
	int i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int strn_cmp(char *s1, char *s2, int len)
{
	int i = 0;

	while (i < len && s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (i == len)
		return (0);
	return (s1[i] - s2[i]);
}

int check_in(char *sub, char *str, int len_sub)
{
	int i = 0;
	int len = str_len(str);
	while (i + len_sub <= len)
	{
		if (strn_cmp(sub, &str[i], len_sub) == 0)
		{
			return (1);
		}
		i++;
	}
	return(0);
}

int main(int argc, char **argv)
{
	int len_max;
	int len;
	int i = 0;
	int j = 0;


	if (argc >= 2)
	{
		len_max = str_len(argv[1]);
		len = len_max;
		while (len >= 0)
		{
			i = 0;
			while (i + len <= len_max)
			{
				j = 2;
				while (j < argc)
				{
					if (!check_in(&argv[1][i], argv[j], len))
						break;
					j++;
				}
				if (j == argc)
				{
					write(1, &argv[1][i], len);
					write(1, "\n", 1);
					return (0);
				}
				i++;
			}
			len--;
		}
	}
	write(1, "\n", 1);
}
