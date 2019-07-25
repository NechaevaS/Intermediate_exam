/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 11:47:00 by snechaev          #+#    #+#             */
/*   Updated: 2019/07/15 12:22:32 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

struct		s_node
{
	int value;
	struct s_node	*left;
	struct s_node	*right;
};

void reverse_tree(struct s_node *root);

void print_tree(struct s_node	*root)
{

	if (!root)
		return ;
	printf("%d  ", root->value);
	if (root->left != NULL)
		printf("l %d  ", root->left->value);
	else
		printf("l %d  ", 0);
	if (root->right != NULL)
		printf("r %d\n", root->right->value);
	else
		printf("r %d\n", 0);
	print_tree(root->left);
	print_tree(root->right);
}
int main()
{
    struct s_node a = {94, 0, 0},
    b = {34, 0, 0},
    c = {52, 0, 0},
    d = {1, 0, 0},
    e = {99, 0, 0},
    f = {20, 0, 0};

    a.left = &b;
	a.right = &c;
    b.left = &d;
    b.right = &e;
    d.left = &f;

    print_tree(&a);
	printf("%c\n" , '\n');
	reverse_tree(&a);
	print_tree(&a);
	return (0);
}