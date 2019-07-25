/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 15:06:55 by snechaev          #+#    #+#             */
/*   Updated: 2019/07/17 11:05:03 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

	struct s_node {
		void *content;
		struct s_node *next;
	};

	struct s_queue {
		struct s_node *first;
		struct s_node *last;
	};

void	print_q(struct s_queue *q)
{
	struct s_node *t = q->first;

	if (!q)
	return ;
	while(t)
	{
		printf("%d\n", (int)(t->content));
		t = t->next;
	}
	printf("\n");
}

struct s_queue *init(void);

	void enqueue(struct s_queue *queue, void *content);

	void *dequeue(struct s_queue *queue);

	void *peek(struct s_queue *queue);

	int isEmpty(struct s_queue *queue);


int main()
{
	struct s_queue	*q0;
	struct s_queue	*q3;

	q3 = init();
	q0 = init();
	printf("q0 %p first %p last %p\n", q0, q0->first, q0->last);
	printf("q0 %p first %p last %p\n", q3, q3->first, q3->last);
	printf("is_em q0 %d\n", isEmpty(q0));
	enqueue(q3, (void *)2);
	enqueue(q3, (void *)3);
	enqueue(q3, (void *)4);
	printf("is_em q3 %d\n", isEmpty(q3));
	print_q(q3);
	printf("peek %d\n", (int)peek(q3));
	printf("pop %d\n", (int)dequeue(q3));
	printf("peek %d\n", (int)peek(q3));

	return (0);
}