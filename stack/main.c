/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 15:06:55 by snechaev          #+#    #+#             */
/*   Updated: 2019/07/11 18:21:02 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

	struct s_node
	{
		void          *content;
		struct s_node *next;
	};

	struct s_stack
	{
		struct s_node *top;
	};

void	print_st(struct s_stack *stack)
{
	struct s_node *t = stack->top;
	if (!stack)
	return ;
	while(t)
	{
		printf("%d\n", *((int *)t->content));
		t = t->next;
	}
}
struct s_stack *init(void);

void *pop(struct s_stack *stack);

void push(struct s_stack *stack, void *content);

void *peek(struct s_stack *stack);

int isEmpty(struct s_stack *stack);


int main()
{
	struct s_stack	*stack;
	int a = 2;
	int b = 16;
	int c = 8;

	stack = init();
	printf("is_em %d\n", isEmpty(stack));
	push(stack, &a);
	push(stack, &b);
	push(stack, &c);
	printf("is_em %d\n", isEmpty(stack));
	print_st(stack);

	return (0);
}