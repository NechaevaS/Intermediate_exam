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

struct s_node {
	int           value;
	struct s_node *right;
	struct s_node *left;
};

void processing(struct s_node *bst, struct s_node **head)
{
    struct s_node *tmp;

    if (!bst)
        return ;
    processing(bst->left, head);
    if (!(bst->left) && !(bst->right) && !(*head))
    {
        *head = bst;
        (*head)->left = *head;
        (*head)->right = *head;
        return ;
    }
    tmp = bst->right;
    bst->right = *head;
    bst->left = (*head)->left;
    (*head)->left->right = bst;
    (*head)->left = bst;
    processing(tmp, head);
}

struct s_node *convert_bst(struct s_node *bst)
{
    struct s_node *head = 0;   
    processing(bst, &head);
    return (head);
}