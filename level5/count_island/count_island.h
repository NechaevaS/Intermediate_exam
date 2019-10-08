/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_island.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 11:15:40 by exam              #+#    #+#             */
/*   Updated: 2019/10/08 11:15:42 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COUNT_ISLAND_H
# define COUNT_ISLAND_H

typedef struct  s_map
{
    char        **m;
	int			h;
	int			w;
    int         num_is;
}				t_map;
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#endif
