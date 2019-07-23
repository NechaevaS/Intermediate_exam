/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ord_alphalong2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 14:21:29 by snechaev          #+#    #+#             */
/*   Updated: 2019/07/23 15:51:04 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ord_alphlong.h"
#include <stdio.h>

int     is_wsps(char c)
{
    return (c == ' ' || c == '\t');
}

t_elem *elem_new(char *str, char **start)
{
    t_elem *new;
    int i = 0;

    new = (t_elem *)malloc(sizeof(t_elem));
    new->data = (char *)malloc(sizeof(char) * 125);

    while (!is_wsps(str[i]))
    {
        new->data[i] = str[i];
        i++;
    }
     while (is_wsps(str[i]))
    {
        i++;
    }
    new->len = i;
    *start = &str[i];
    return (new);
}

void add_to_q(t_queue *q, char *str)
{
    char *start;
    t_elem *elem;

    start = str;
    while (*start != '\0')
    {
        if (q->first == NULL)
        {
            elem = elem_new(str, &start);
            q->first = elem;
        }
        else
        {
            elem = elem_new(start, &start);
            q->last->next = elem;
        }
    }
}
int cmp_str(char *s1, char *s2)
{
	int i = 0;
	char  tmp1;
	char tmp2;

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

int is_less(t_elem *a, t_elem *b)
{
    if (a->len < b->len)
        return (1);
    if (a->len == b->len)
    {
        if (cmp_str(a->data, b->data) == -1)
        return (1);
    }
    return (0);
}

t_queue	*sort_q(t_queue *q)
{
	t_elem *head;
	t_elem *current;
	t_elem *tmp;

	head = q->first;
	while (head)
	{
		current = head->next;
		while (current)
		{
			if (is_less(head, current) != 1)
			{
				tmp = head;
				head = current;
				current = tmp;
			}
			current = current->next;
		}
		head = head->next;
	}
	return(q);
}

t_queue *init(void)
{
	t_queue *q;

	q = (t_queue *)malloc(sizeof(t_queue));
	if (!q)
		return (NULL);
	q->first = NULL;
	q->last = NULL;
	return (q);
}
void	print_q(t_queue *q)
{
	t_elem *t = q->first;

	if (!q)
	return ;
	while(t)
	{
        printf("%s", t->data);
        if (t->next->len == t->len)
            write(1, " ", 1);
        else
            write(1, "\n", 1);
		t = t->next;
	}
	printf("\n");
}
int   main(int argc, char ** argv)
{
    t_queue *q;

    if (argc != 2)
    {
        write(1, "\n", 1);
        return (0);
    }
    q = init();
    add_to_q(q, argv[1]);
    sort_q(q);
    print_q(q);
    return (0);
}