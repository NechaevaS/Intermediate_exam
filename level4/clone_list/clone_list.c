/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clone_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:22:21 by snechaev          #+#    #+#             */
/*   Updated: 2019/10/07 18:07:19 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

struct s_node
{
	int           data;
	struct s_node *next;
	struct s_node *other;
};

struct s_node *clone_list(struct s_node *node)
{
    struct s_node *elem;
    struct s_node *new;
    struct s_node *head;
    struct s_node *curr;

    if (!node)
        return (NULL);
    curr = node;
    while(curr)
    {
        elem = (struct s_node *)malloc(sizeof(struct s_node));
        elem->data = curr->data;
        elem->other = NULL;
        elem->next = curr->next;
        curr->next = elem;
        curr = curr->next->next;   
    }
    curr = node;
    while(curr)
    {
        if (curr->other)
            curr->next->other = curr->other->next;
        curr = curr->next->next;
    }
    curr = node;
    new = curr->next;
    head = new;
    curr->next = head->next;
    while (head->next)
    {
        curr = curr->next;
        head->next = curr->next;
        curr->next = head->next->next;
        head = head->next;
    }
    return (new);
}

