/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 11:20:13 by snechaev          #+#    #+#             */
/*   Updated: 2019/07/17 13:06:42 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_node 
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

int count_node(struct s_node *n, int n_nodes, int *can)
{
    int l_node;
    int r_node;
    if (!n)
        return (0);
    l_node = count_node(n->left, n_nodes, can);
    r_node = count_node(n->right, n_nodes, can);
    if ((l_node + r_node + 1) * 2 == n_nodes)
        *can = 1;
    return (l_node + r_node + 1);
}

int	can_split(struct s_node *n)
{
    int res = 0;
    int all_nodes;
    int cur_nodes;

    all_nodes = count_node(n, 0, &res); /* ignore res */
    cur_nodes = count_node(n, all_nodes, &res);
    all_nodes = cur_nodes; /* for using cur_nodes */
    return (res);
}