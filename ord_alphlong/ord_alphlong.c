/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ord_alphlong.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 13:17:08 by snechaev          #+#    #+#             */
/*   Updated: 2019/07/15 15:10:07 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ord_alphlong.h"

t_list *create_list(char *str)
{
	int i = 0;
	int j;
	t_list *head;
	t_list *current;
	int n = count_words(str);

	current = head;
	while (str[i] != '\0')
	{
		if ((str[i - 1] == ' ' || str[i - 1] == '\t' || i == 0)
		&& (str[i] != ' ' && str[i] != '\t'))
		{
			t_list *list = malloc(sizeof(t_list));
			j = 0;
			while (str[i] != ' ' && str[i] != '\t')
			{
				current->word[j] = str[i];
				i++;
				j++;
			}
			current->word[j] = '\0';
			i--;
			current->len = j;
			current = current->next;
		}
		i++;
	}
	return (head);
}
int cmp_str(char *s1, char *s2)
{
	int i = 0;
	char  tmp1;
	char tmp2;
	int res;

	while (s1[i] || s2[i])
	{
		if ((s1[i] > 'A' && s1[i]< 'Z') && (s2[i] > 'A' && s2[i]< 'Z'))
		{
			tmp1 = s1[i] + 32;
			tmp2 = s2[i] + 32;
		}
		else
		{
			tmp1 = s1[i];
			tmp2 = s2[i];
		}
		if (tmp1 < tmp2)
			return (-1);
		else if (tmp1 > tmp2)
			return (1);
		else
			i++;
	}
	return (0);
}

t_list	*sort_word(t_list* lst)
{
	t_list *head;
	t_list *current;
	t_list *tmp;

	head = lst;
	while (lst)
	{
		current = lst->next;
		while (current)
		{
			if (lst->len  == current->len)
			{
				if (ifcmp_str(lst->word, current->word) == -1)
				tmp = lst;
				lst = current;
				current = tmp;
			}
			current = current->next;
		}
		lst = lst->next;
	}
	return(head);
}
t_list	*sort_len(t_list* lst)
{
	t_list *head;
	t_list *current;
	t_list *tmp;

	head = lst;
	while (lst)
	{
		current = lst->next;
		while (current)
		{
			if (lst->len > current->len)
			{
				tmp = lst;
				lst = current;
				current = tmp;
			}
			current = current->next;
		}
		lst = lst->next;
	}
	return(head);
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

int main(int argc, char **argv)
{
	int i;
	t_list *list;

	if (argc == 2)
	{
		list = create_list(argv[1]);
		list = sort_len(list);
		list = sort_word(list);
		i = 1;
		while (list)
		{
			print(list->word);
			if(list->len == list->next->len)
			{
				write(1, " ", 1);
			}
			write(1, "\n", 1);
			list = list->next;
		}

	}
	write(1, "\n", 1);
	return (0);
}