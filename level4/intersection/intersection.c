/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 15:03:48 by snechaev          #+#    #+#             */
/*   Updated: 2019/07/25 15:11:26 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_node
{
	void *content;
	struct s_node *next;
};

void *intersection(struct s_node *lst1, struct s_node *lst2)
{
    void *res = 0;
    struct s_node *l1;
    struct s_node *l2;

	if (lst1 && lst2)
	{
		l1 = lst1;
		l2 = lst2;
		while(l1 != l2)
		{
			if (!l1 && l2)
				l1 = lst2;
			if (!l2 && l1)
				l2 = lst1;
			l1 = l1->next;
			l2 = l2->next;
		}
		if (l1)
				return (l1->content);
	}
    return (res);
}