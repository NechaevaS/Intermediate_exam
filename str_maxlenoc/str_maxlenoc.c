/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_maxlenoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 14:02:34 by snechaev          #+#    #+#             */
/*   Updated: 2019/07/12 15:41:08 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char *find_substr(char *s, char *sub, int len_sub)
{
	int i = 0;
	int j = 0;
	int tmp;
	char *res;

	while (s[i] != '\0')
	{
		if (s[i] == sub[j])
		{
			j = 0;
			tmp = i;
			while (j < len_sub)
			{
				if (s[tmp] != sub[j])
					break;
				tmp++;
				j++;
			}
			if (j == len_sub)
			{
				res = &s[i];
				return (res);
			}
		}
		i++;
	}
	return (NULL);
}

void	print_s(char *s, int len)
{
	int i = 0;
	while (i < len)
	{
		write(1, &s[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int i = 0;
	int j = 0;
	int total_len = 0;
	int len = 0;

	if (argc > 2)
	{
		while (argv[1][total_len] != '\0')
		{
			total_len++;
		}

		len = total_len;
		while(len > 0)
		{
			while(j + len <= total_len)
			{
				i = 2;
				while(i < argc)
				{
					if (find_substr(argv[i], argv[1], len) != NULL)
						i++;
					else
						break;
				}
				if (i == argc)
				{
					print_s(argv[1], len);
					write(1, "\n", 1);
					return (0);
				}
				j++;
			}
			len--;
		}
	}
	write(1, "\n", 1);
	return (0);
}


