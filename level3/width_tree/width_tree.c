/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 11:39:04 by snechaev          #+#    #+#             */
/*   Updated: 2019/07/15 11:59:19 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_node 
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

int tree_depth(struct s_node *n, int *max)
{
    int l_depth;
    int r_depth;
    int curr_width;

    if (!n)
        return (0);
    l_depth = tree_depth(n->left, max);
    r_depth = tree_depth(n->right, max);
    curr_width = l_depth + r_depth + 1;
    if (curr_width > *max)
        *max = curr_width;
    if (l_depth > r_depth)
        return (l_depth + 1);
    return (r_depth + 1);
}

int	width_tree(struct s_node *n)
{
    int max = 0;

    tree_depth(n, &max);
    return (max);
}