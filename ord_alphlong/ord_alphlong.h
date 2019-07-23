/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ord_alphlong.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 13:05:44 by snechaev          #+#    #+#             */
/*   Updated: 2019/07/23 14:43:17 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ORD_ALPHLONG_H
# define ORD_ALPHLONG_H

typedef struct s_node
{
	char			*data;
	int				len;
	struct s_node	*next;
}					t_elem;

typedef struct s_queue
{
	struct s_node	*first;
	struct s_node	*last;
}					t_queue;
// typedef struct		s_list
// {
// 	char			*word;
// 	int				len;
// 	struct s_list	*next;
// 	struct s_list	*first;
// 	struct s_list	*last;
// }					t_list;

#endif