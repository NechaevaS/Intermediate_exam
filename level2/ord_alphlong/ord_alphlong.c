/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ord_alphlong.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 13:17:08 by snechaev          #+#    #+#             */
/*   Updated: 2019/08/05 14:46:22 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ord_alphlong.h"

int is_wsps(char c)
{
	return (c == ' ' || c == '\t');
}

int count_word(char *str)
{
	int i = 0;
	int count = 0;
	while (str[i])
	{
		if (!is_wsps(str[i]) && (i == 0 || is_wsps(str[i - 1])))
			count++;
		i++;
	}
	return (count);
}
void fill_words(char *str, t_words *words)
{
	int w_len = 0;
	int i = 0;
	int j = 0;
	while (str[i] != '\0')
	{
		if (!is_wsps(str[i]) && (i == 0 || str[i - 1] == 0))
		{
			w_len = 0;
			words[j].word = &str[i];
			while (str[i] && !is_wsps(str[i]))
			{
				w_len++;
				i++;
			}
			words[j].len = w_len;
			j++;
		}
		if (is_wsps(str[i]))
			str[i] = 0;
		i++;
	}
}

int str_cmp(char *s1, char *s2)
{
	int i = 0;
	char c1;
	char c2;

	while (s1[i] && s2[i])
	{
		if (s1[i] >= 'A' && s1[i] <= 'Z')
			c1 = s1[i] + 32;
		else
			c1 = s1[i];
		if (s2[i] >= 'A' && s2[i] <= 'Z')
			c2 = s2[i] + 32;
		else
			c2 = s2[i];

		if (c1 != c2)
			return (c1 - c2);
		else
			i++;
	}
	return (0);
}

int is_less(t_words w1, t_words w2)
{
	if (w1.len < w2.len)
		return (1);
	if (w1.len == w2.len)
	{
		if (str_cmp(w1.word, w2.word) <= 0)
			return (1);
	}
	return (0);
}
void sort_words(t_words *words, int len)
{
	int tmp;
	char *t = NULL;
	int i = 0;
	int j = 0;

	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (!(is_less(words[i], words[j])))
			{

				tmp = words[i].len;
				words[i].len = words[j].len;
				words[j].len = tmp;
				t = words[i].word;
				words[i].word = words[j].word;
				words[j].word = t;
			}
			j++;
		}
		i++;
	}
}
void print(t_words *words, int n_words)
{
	int n = 0;
	int i = 0;
	while (n < n_words)
	{
		i = 0;
		while (words[n].word[i])
		{
			write(1, &words[n].word[i], 1);
			i++;
		}
		if ( n != n_words - 1 && words[n].len == words[n + 1].len)
			write(1, " ", 1);
		else
			write(1, "\n", 1);
		n++;
	}
}

int main(int argc, char **argv)
{
	char *str;
	t_words *words;
	int n_words = 0;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}

	str = argv[1];

	n_words = count_word(str);
	words = (t_words *)malloc(sizeof(t_words) * n_words);
	fill_words(str, words);
	sort_words(words, n_words);
	print(words, n_words);
	return (0);
}
