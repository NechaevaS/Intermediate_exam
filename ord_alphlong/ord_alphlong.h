/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ord_alphlong.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 13:05:44 by snechaev          #+#    #+#             */
/*   Updated: 2019/07/15 13:48:56 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ORD_ALPHLONG_H
# define ORD_ALPHLONG_H

typedef struct		s_list
{
	char			*word;
	int				len;
	struct s_list	*next;
}					t_list;

#endif