/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_bst.c                                        :+:      :+:    :+:   */
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
	struct s_node *right;
	struct s_node *left;
};

struct s_node *find_max(struct s_node *bst)
{
	while(bst->right)
		bst = bst->right;
	return (bst);
}

struct s_node *find_min(struct s_node *bst)
{
	while(bst->left)
		bst = bst->left;
	return (bst);
}

void traverce(struct s_node *bst, struct s_node *min, struct s_node *max)
{
	static struct s_node *tmp;

	if (!bst)
		return ;

	if (bst != min)
		traverce(bst->left, min, max);
	if (tmp)
	{
		bst->left = tmp;
		tmp->right = bst;
	}
	tmp = bst;
	if (bst != max)
		traverce(bst->right, min, max);
}

struct s_node *convert_bst(struct s_node *bst)
{
	struct s_node *min;
	struct s_node *max;

	if (!bst)
		return (0);
	min = find_min(bst);
	max = find_max(bst);

	min->left = max;
	max->right = min;
	traverce(bst, min, max);
	return (min);
}
