/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 15:03:48 by snechaev          #+#    #+#             */
/*   Updated: 2019/08/09 12:56:53 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_node
{
	void *content;
	struct s_node *next;
};

void *intersection(struct s_node *lst1, struct s_node *lst2)
{
	struct s_node *one;
	struct s_node *two;

	if (!lst1 || !lst2)
		return (0);
	one = lst1;
	while (one)
	{
		two = lst2;
		while (two)
		{
			if (one == two)
				return (one);
			two = two->next;
		}
		one = one->next;
	}
	return (0);
}

