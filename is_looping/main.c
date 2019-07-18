/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 15:23:17 by snechaev          #+#    #+#             */
/*   Updated: 2019/07/17 15:34:45 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

struct s_node
{
	int value;
	struct s_node *next;
};

int	is_looping(struct s_node *node);

void test1()
{
	struct s_node n1 = {1, 0},
	n2 = {1, 0},
	n3 = {1, 0},
	n4 = {1, 0},
	n5 = {1, 0},
	n6 = {1, 0};

	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;
	n5.next = &n6;
	n6.next = &n3;

	printf("test 1 %d\n", is_looping(&n1));
}
void test2()
{
	struct s_node n1 = {1, 0},
	n2 = {1, 0},
	n3 = {1, 0},
	n4 = {1, 0},
	n5 = {1, 0},
	n6 = {1, 0};

	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;
	n5.next = &n6;
	n6.next = NULL;

	printf("test 2 %d\n", is_looping(&n1));
}
int	main()
{
	test1();
	test2();
	return (0);
}