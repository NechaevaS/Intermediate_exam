/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_looping.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 15:16:13 by snechaev          #+#    #+#             */
/*   Updated: 2019/07/17 15:42:15 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_node
{
	int value;
	struct s_node *next;
};

int	is_looping(struct s_node *node)
{
	struct s_node *one;
	struct s_node *two;

	if (!node)
		return (0);
	one = node;
	two = node;
	while(one && two)
	{
		one = one->next;
		two = two->next->next;
		if(one == two)
			return (1);
	}
	return (0);
}