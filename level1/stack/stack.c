/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 09:26:07 by exam              #+#    #+#             */
/*   Updated: 2019/09/24 09:26:08 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

struct s_node
{
	void          *content;
	struct s_node *next;
};

struct s_stack
{
    struct s_node *top;
};

struct s_stack *init(void);

void *pop(struct s_stack *stack);

void push(struct s_stack *stack, void *content);

void *peek(struct s_stack *stack);

int isEmpty(struct s_stack *stack);

struct s_stack *init(void)
{
    struct s_stack *stack;

    stack = (struct s_stack *)malloc(sizeof(struct s_stack));
    stack->top = NULL;
    return (stack);
}

int isEmpty(struct s_stack *stack)
{
    if (!stack || !stack->top)
        return (1);
    return (0);
}

void push(struct s_stack *stack, void *content)
{
    struct s_node *elem;

    if (!stack)
        return ;
    elem = (struct s_node *)malloc(sizeof(struct s_node));
    elem->content = content;
    elem->next = NULL;
    elem->next = stack->top;
    stack->top = elem;
}

void *pop(struct s_stack *stack)
{
    struct s_node   *tmp;
    void            *data;

    if (isEmpty(stack))
        return (NULL);
    tmp = stack->top;
    data = tmp->content;
    stack->top = tmp->next;
    free(tmp);
    return (data);
}

void *peek(struct s_stack *stack)
{
    if (isEmpty(stack))
        return (NULL);
    return (stack->top->content);
}