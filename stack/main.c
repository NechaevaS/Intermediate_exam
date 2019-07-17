/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 15:06:55 by snechaev          #+#    #+#             */
/*   Updated: 2019/07/17 10:20:28 by snechaev         ###   ########.fr       */
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
		printf("%d\n", (int)(t->content));
		t = t->next;
	}
	printf("\n");
}

struct s_stack *init(void);

void *pop(struct s_stack *stack);

void push(struct s_stack *stack, void *content);

void *peek(struct s_stack *stack);

int isEmpty(struct s_stack *stack);


int main()
{
	struct s_stack	*stack0;
	struct s_stack	*stack3;

	stack3 = init();
	stack0 = init();
	printf("stack0 %p top %p\n", stack0, stack0->top);
	printf("stack0 %p top %p\n", stack3, stack0->top);
	printf("is_em %d\n", isEmpty(stack0));
	push(stack3, (void *)2);
	push(stack3, (void *)3);
	push(stack3, (void *)4);
	printf("is_em %d\n", isEmpty(stack3));
	print_st(stack3);
	printf("peek %d\n", (int)peek(stack3));
	printf("pop %d\n", (int)pop(stack3));
	printf("peek %d\n", (int)peek(stack3));


	return (0);
}