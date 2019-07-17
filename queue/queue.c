/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 09:29:38 by exam              #+#    #+#             */
/*   Updated: 2019/07/17 11:03:45 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

struct s_node
{
	void *content;
	struct s_node *next;
};

struct s_queue
{
	struct s_node *first;
	struct s_node *last;
};

struct s_queue *init(void);

void enqueue(struct s_queue *queue, void *content);

void *dequeue(struct s_queue *queue);

void *peek(struct s_queue *queue);

int isEmpty(struct s_queue *queue);

struct s_queue *init(void)
{
	struct s_queue *q;

	q = (struct s_queue *)malloc(sizeof(struct s_queue));
	if (!q)
		return (NULL);
	q->first = NULL;
	q->last = NULL;
	return (q);
}

int isEmpty(struct s_queue *queue)
{
	if (queue->first == NULL)
		return (1);
	return (0);
}

void enqueue(struct s_queue *queue, void *content)
{
	struct s_node *item;

	item =(struct s_node *)malloc(sizeof(struct s_node));
	item->content = content;
	if (queue->first == NULL)
	{
		queue->first = item;
	}
	else
	{
		queue->last->next = item;
		item->next = NULL;
	}
	queue->last = item;
}

void *dequeue(struct s_queue *queue)
{
	void	*content;
	struct s_node	*tmp;

	if (isEmpty(queue) == 1)
        return (NULL);
	content = queue->first->content;
	tmp = queue->first;
	queue->first = queue->first->next;
	free(tmp);
	return (content);
}

void *peek(struct s_queue *queue)
{
	 if (isEmpty(queue) == 1)
        return (NULL);
	 return(queue->first->content);
}




