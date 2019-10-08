/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infin_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 13:21:17 by snechaev          #+#    #+#             */
/*   Updated: 2019/10/08 15:11:44 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int str_len(char *s)
{
	int i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char *fill_str(char *s, int lenmax, int len)
{
	char *str;
	str = (char *)malloc(sizeof(char) * lenmax);
	str[lenmax - 1] = '\0';
	lenmax = lenmax - 2;
	len--;
	while (lenmax >= 0)
	{
		if (len < 0)
			str[lenmax] = '0';
		else
			str[lenmax] = s[len];
		len--;
		lenmax--;
	}
	return (str);
}

char *summing(char *s1, char *s2, int lenmax)
{
	int sum = 0;
	int in_m = 0;
	char *res;
	int i;

	res = (char *)malloc(sizeof(char) * lenmax);
	i = lenmax - 1;
	res[i] = '\0';
	i--;
	while (i > 0)
	{
		sum = ((s1[i] - '0') + (s2[i] - '0'));
		if (in_m)
		{
			sum = sum + in_m;
			in_m = 0;
		}
		if (sum > 9)
		{
			in_m++;
			res[i] = (sum % 10 + '0');
		}
		else
			res[i] = (sum + '0');
		i--;
	}
	res[i] = in_m + '0';
	return (res);
}

char *subtraction(char *s1, char *s2, int lenmax)
{
	int sub = 0;

	char *res;
	int i;

	res = (char *)malloc(sizeof(char) * lenmax);
	i = lenmax - 1;
	res[i] = '\0';
	i--;
	while (i >= 0)
	{
		if (s1[i] < s2[i])
		{
			s1[i - 1] = s1[i - 1] - 1;
			s1[i] = s1[i] + 10;
		}
		sub = ((s1[i] - '0') - (s2[i] - '0'));
		res[i] = (sub + '0');
		i--;
	}
	return (res);
}

void print_sum(char *summ, int sign)
{
	int i = 0;

	while (summ[i] == '0' && summ[i])
		i++;
	if (summ[i] == '\0')
	{
		write(1, "0", 1);
		return;
	}
	if (sign)
		write(1, "-", 1);
	while (summ[i])
	{
		write(1, &summ[i], 1);
		i++;
	}
}

int main(int argc, char **argv)
{
	char *s1;
	char *s2;
	char *summ;
	int len1;
	int len2;
	int lenmax;
	int sign1 = 0;
	int sign2 = 0;
	if (argc == 3)
	{
		len1 = str_len(argv[1]);
		len2 = str_len(argv[2]);
		if (argv[1][0] == '-')
		{
			sign1 = 1;
			len1--;
			argv[1]++;
		}
		if (argv[2][0] == '-')
		{
			sign2 = 1;
			len2--;
			argv[2]++;
		}
		if (len1 > len2)
			lenmax = len1 + 2;
		else
			lenmax = len2 + 2;
		s1 = fill_str(argv[1], lenmax, len1);
		s2 = fill_str(argv[2], lenmax, len2);
		if (sign1 == sign2)
		{
			summ = summing(s1, s2, lenmax);
			if (!sign1)
				print_sum(summ, 0);
			else
				print_sum(summ, 1);
		}
		else
		{
			if (len1 > len2)
			{
				summ = subtraction(s1, s2, lenmax);
				if (sign1)
					print_sum(summ, 1);
				else
					print_sum(summ, 0);
			}
			else
			{
				summ = subtraction(s2, s1, lenmax);
				if (sign2)
				print_sum(summ, 1);
				else
				print_sum(summ, 0);
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}
