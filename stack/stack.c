/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 15:43:30 by snechaev          #+#    #+#             */
/*   Updated: 2019/07/11 18:16:52 by snechaev         ###   ########.fr       */
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
	struct s_stack	*stack;

	if (!(stack = (struct s_stack *)malloc(sizeof(struct s_stack))))
		return (NULL);
	stack->top = NULL;
	return (stack);
}

void	*pop(struct s_stack *stack)
{
	struct s_node *item;

	if(isEmpty(stack) == 0)
	{
		item = stack->top;
		stack->top = stack->top->next;
		return (item->content);
	}
	else
	{
		return (NULL);
	}
}

void	push(struct s_stack *stack, void *content)
{
	struct s_node *item;

	if(!stack)
		return ;
	if ((item = malloc(sizeof(struct s_node))) == NULL)
		return ;
	item->content = content;
	item->next = stack->top;
	stack->top = item;
}

void	*peek(struct s_stack *stack)
{
	if(isEmpty(stack) == 1)
		return (NULL);
	else
		return(stack->top->content);
}

int isEmpty(struct s_stack *stack)
{
	if (stack->top == NULL)
		return (0);
	else
		return(1);
}