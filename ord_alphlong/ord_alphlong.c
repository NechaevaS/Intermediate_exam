/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ord_alphlong.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 13:17:08 by snechaev          #+#    #+#             */
/*   Updated: 2019/07/25 09:49:11 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ord_alphlong.h"

int is_wsps(char c)
{
	return (c == ' ' || c == '\t');
}

int cmp_str(char *s1, char *s2)
{
	int i = 0;
	char tmp1;
	char tmp2;
	int res;

	while (s1[i] && s2[i])
	{
		if ((s1[i] > 'A' && s1[i] < 'Z'))
			tmp1 = s1[i] + 32;
		else if ((s2[i] > 'A' && s2[i] < 'Z'))
			tmp2 = s2[i] + 32;
		else
		{
			tmp1 = s1[i];
			tmp2 = s2[i];
		}
		if (tmp1 != tmp2)
		{
			res = tmp1 - tmp2;
			return (res);
		}
		i++;
	}
	res = tmp1 - tmp2;
	return (res);
}

int is_less(t_words a, t_words b)
{
	if (a.len < b.len)
		return (1);
	if (a.len == b.len)
	{
		if (cmp_str(a.word, b.word) < 0)
			return (1);
	}
	return (0);
}

void print_str(char *s)
{
	int i = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
}

int count_words(char *str)
{
	int i = 0;
	int count = 0;

	while (str[i] != '\0')
	{

		if (!is_wsps(str[i]) && (i == 0 || str[i - 1] == 0))
		{
			count++;
		}
		if (is_wsps(str[i]))
			str[i] = 0;
		i++;
	}
	return (count);
}
int str_len(char *s)
{
	int i = 0;
	while (s[i] != 0)
	{
		i++;
	}
	return (i);
}

void fill_arr(t_words *arr, char *str, int len)
{
	int i = 0;
	int j = 0;

	while (i < len)
	{
		if (!is_wsps(str[i]) && (str[i - 1] == 0 || i == 0))
		{
			arr[j].len = str_len(&str[i]);
			arr[j].word = &str[i];
			j++;
		}
		i++;
	}
}

void sort(t_words *arr, int len)
{
	int i = 0;
	int j;
	int t_len;
	char *t_p;

	while (i < len)
	{
		j = i + 1;
		while (j < len )
		{
			if (!is_less(arr[i], arr[j]))
			{
				t_len = arr[i].len;
				arr[i].len = arr[j].len;
				arr[j].len = t_len;

				t_p = arr[i].word;
				arr[i].word = arr[j].word;
				arr[j].word = t_p;
			}
			j++;
		}
		i++;
	}
}

int main(int argc, char **argv)
{
	int i;
	int len;
	t_words *arr;
	int n_words;

	if (argc == 2)
	{
		len = str_len(argv[1]);
		n_words = count_words(argv[1]);
		arr = (t_words *)malloc(sizeof(t_words) * n_words);
		fill_arr(arr, argv[1], len);
		sort(arr, n_words);
		i = 1;
		write(1, arr[0].word, arr[0].len);
		while (i < n_words)
		{
			if (arr[i].len == arr[i - 1].len)
				write(1, " ", 1);
			else
				write(1, "\n", 1);

			write(1, arr[i].word, arr[i].len);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}