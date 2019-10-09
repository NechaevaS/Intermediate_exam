/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_diam.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 15:36:34 by snechaev          #+#    #+#             */
/*   Updated: 2019/10/09 16:48:36 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "g_diam.h"
#include <stdio.h>

int ft_atoi(char **s)
{
    int res = 0;

    while((**s) >= '0' && (**s) <= '9')
    {
        res = res * 10 + (**s) - '0';
        (*s)++;
    }
    if (**s)
         (*s)++;
    return (res);
}

int *parse(char *s, int n, int *max)
{
    int *w;
    int i = 0;

    w = (int *)malloc(sizeof(int) * n);
    while (*s)
    {
       
        w[i] = ft_atoi(&s);
        printf("%d ", w[i]);
        if (w[i] > *max)
            *max = w[i];
        i++;
    }
    return (w);
}

int main(int argc, char **argv)
{
    int *w;
    int i = 0;
    int nodes = 0;
    int max = 0;

    if (argc != 2)
        return (1);
    while (argv[1][i])
    {
        if (i == 0 || argv[1][i - 1] == ' ' || argv[1][i - 1] == '-')
            nodes++;
        i++;
    }
    printf("%d\n", nodes);
    w = parse(argv[1], nodes, &max);
}
