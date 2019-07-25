/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_sequence.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 14:02:34 by snechaev          #+#    #+#             */
/*   Updated: 2019/07/12 15:41:08 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct		s_node 
{
	int value;
	struct s_node	*left;
	struct s_node	*right;
};

void	check_path(struct s_node *node, int curr_path, int *max_path, int pr_val)
{
	if (!node)
		return ;
	if (node->value - 1 == pr_val)
		curr_path++;
	else
		curr_path = 1;
	if (curr_path > *max_path)
		*max_path = curr_path;
	check_path(node->left, curr_path, max_path, node->value);
	check_path(node->right, curr_path, max_path, node->value);
}

int	longest_sequence(struct s_node *node)
{
	int max_path = 1;

	if (!node)
		return (0);

	check_path(node->left, 1, &max_path, node->value);
	check_path(node->right, 1, &max_path, node->value);
	return (max_path);
}