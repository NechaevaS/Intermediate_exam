/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_sequence.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 14:02:34 by snechaev          #+#    #+#             */
/*   Updated: 2019/08/12 16:25:54 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_node
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

void count_node(struct s_node *node, int *max, int curr, int pr_val)
{
	if (!node)
		return ;
	if (node->value == pr_val + 1)
		curr++;
	else
		curr = 1;
	if (curr > *max)
		*max = curr;
	count_node(node->left, max, curr, node->value);
	count_node(node->right, max, curr, node->value);
}

int	longest_sequence(struct s_node *node)
{
	int max = 1;

	if (!node)
		return (0);
	if(node->left)
		count_node(node->left, &max, 1, node->value);
	if(node->right)
		count_node(node->right, &max, 1, node->value);
	return (max);
}