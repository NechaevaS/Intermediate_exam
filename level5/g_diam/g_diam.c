/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_diam.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 15:36:34 by snechaev          #+#    #+#             */
/*   Updated: 2019/10/10 18:09:48 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "g_diam.h"
#include <stdio.h>

void print_graph(int **g, int n)
{
    int i = 0;
    int j;

    while (i < n)
    {
        j = 0;
        while (j < n)
        {
            printf("%d ", g[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
}

int ft_atoi(char **s)
{
    int res = 0;

    while ((**s) >= '0' && (**s) <= '9')
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
        if (w[i] > *max)
            *max = w[i];
        i++;
    }
    return (w);
}

int **create_graph(int *arr, int max, int nodes)
{
    int **g;
    int i = 0;
    int j = 0;
    int k = 0;

    g = (int **)malloc(sizeof(int *) * max);
    while (i < max)
    {
        j = 0;
        g[i] = (int *)malloc(sizeof(int) * max);
        while (j < max)
        {
            g[i][j] = 0;
            j++;
        }
        i++;
    }

    while (k + 1 < nodes)
    {
        j = arr[k];
        i = arr[k + 1];
        if (g[j][i] == 0)
        {
            g[j][i] = 1;
            g[i][j] = 1;
        }
        k = k + 2;
    }
    print_graph(g, max);
    return (g);
}

int find_max_help(int **g, int n, int j)
{
    int i = 0;
    int cur;
    int m_cur = 0;

    while (i < n)
    {
        if (g[j][i])
        {
            g[j][i] = 0;
            g[i][j] = 0;
            cur = find_max_help(g, n, i) + 1;
            if (cur > m_cur)
                m_cur = cur;
            g[j][i] = 1;
            g[i][j] = 1;
        }
        i++;
    }
    return (m_cur);
}

int find_max(int **g, int n)
{
    int j = 0;
    int cur;
    int m_cur = 0;

    while (j < n)
    {
        cur = find_max_help(g, n, j) + 1;
        if (cur > m_cur)
                m_cur = cur;
        j++;
    }
    return (m_cur);
}

int main(int argc, char **argv)
{
    int *w;
    int i = 0;
    int nodes = 0;
    int max = 0;
    int **g;
    int res;

    if (argc != 2)
        return (1);
    while (argv[1][i])
    {
        if (i == 0 || argv[1][i - 1] == ' ' || argv[1][i - 1] == '-')
            nodes++;
        i++;
    }
    w = parse(argv[1], nodes, &max);
    printf("%d\n", max);
    g = create_graph(w, max + 1, nodes);
    res = find_max(g, max) + 1;
    printf("%d\n", res);
    return (0);
}
