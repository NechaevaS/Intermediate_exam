/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 15:43:30 by snechaev          #+#    #+#             */
/*   Updated: 2019/07/30 15:54:32 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

struct s_node
{
	void *content;
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
	if (!stack || stack->top == NULL)
		return (1);
	return (0);
}

void push(struct s_stack *stack, void *content)
{
	struct s_node *item;

	if (!stack)
		return;
	item = (struct s_node *)malloc(sizeof(struct s_node));
	item->content = content;
	item->next = stack->top;
	stack->top = item;
}

void *pop(struct s_stack *stack)
{
	void *data;
	struct s_node *tmp;

	if (isEmpty(stack))
		return (NULL);
	data = stack->top->content;
	tmp = stack->top;
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

