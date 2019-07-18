/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perimeter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 16:08:47 by snechaev          #+#    #+#             */
/*   Updated: 2019/07/17 17:27:51 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

struct s_node
{
	int           value;
	struct s_node *right;
	struct s_node *left;
};

void print_left(struct s_node *root)
{
	struct s_node *t;
	t = root;
	if (!t)
		return ;
	if (t->left || t->right)
		printf("%d ", t->value);
	print_left(t->left);
}

void print_child(struct s_node *root)
{
	struct s_node *t;
	t = root;
	if (!t)
		return ;
	if (!(t->left) && !(t->right))
		printf("%d ", t->value);
	print_child(t->left);
	print_child(t->right);
}

void print_right(struct s_node *root, struct s_node *curr)
{
	struct s_node *t;

	t = curr;
	if (!t)
		return ;

	print_right(root, t->right);
	if (t->left || t->right)
	{
		printf("%d", t->value);
		if (t->value != root->right->value)
			printf(" ");
	}
}

void perimeter(struct s_node *root)
{
	print_left(root);
	print_child(root);
	print_right(root, root->right);
	printf("\n");
}
