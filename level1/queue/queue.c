/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 09:18:09 by exam              #+#    #+#             */
/*   Updated: 2019/09/10 09:18:13 by exam             ###   ########.fr       */
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
    struct s_queue *queue;

    queue = (struct s_queue *)malloc(sizeof(struct s_queue));
    queue->last = NULL;
    queue->first = NULL;
    return (queue);
}

int isEmpty(struct s_queue *queue)
{
    if (!queue || !(queue->first))
        return (1);
    return (0);
}

void enqueue(struct s_queue *queue, void *content)
{
    struct s_node *elem;

    if (!queue)
        return ;
    elem = (struct s_node *)malloc(sizeof(struct s_node));
    elem->content = content;
    elem->next = NULL;
    if (!(queue->first))
    {
        queue->first = elem;
        queue->last = elem;
    }
    else
    {
        queue->last->next = elem;
        queue->last = elem;
    }
}

void *peek(struct s_queue *queue)
{
    if (isEmpty(queue))
        return (NULL);
    return(queue->first->content);
}

void *dequeue(struct s_queue *queue)
{
    struct s_node *tmp;
    void *data;

    if (isEmpty(queue))
        return (NULL);
    tmp = queue->first;
    data = tmp->content;
    queue->first = tmp->next;
    free(tmp);
    return (data);
}
