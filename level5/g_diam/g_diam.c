/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_diam.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 15:36:34 by snechaev          #+#    #+#             */
/*   Updated: 2019/10/10 17:00:05 by snechaev         ###   ########.fr       */
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

int *parse(char *s, int n, int *max, int *min)
{
    int *w;
    int i = 0;

    w = (int *)malloc(sizeof(int) * n);
    while (*s)
    {
        w[i] = ft_atoi(&s);
        if (i == 0)
            *min = w[i];
        if (w[i] > *max)
            *max = w[i];
        if (w[i] < *min)
            *min = w[i];
        i++;
    }
    return (w);
}

static int m;
// void find_max(int **g, int n, int cur, int j)
// {
//     int i = 0;

//     i = 0;
//     while (i < n)
//     {
//         if (g[j][i])
//         {
//             cur++;
//             if (cur > m)
//                 m = cur;
//             g[j][i] = 0;
//             g[i][j] = 0;
//             find_max(g, n, cur, i);
//             g[j][i] = 1;
//             g[i][j] = 1;
//         }
//         i++;
//     }
// }

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
static int m;
void find_max_help(int **g, int n, int cur, int j, int min)
{
    int i = 0;

    if (m == 0 && j > min)
        return;
    while (i < n)
    {
        if (g[j][i])
        {
            cur++;
            if (cur > m)
                m = cur;
            g[j][i] = 0;
            g[i][j] = 0;
            find_max_help(g, n, cur, i, min);
            g[j][i] = 1;
            g[i][j] = 1;
         //   cur = 2;
        }
        i++;
    }
}

void find_max(int **g, int n, int min)
{
    int j = 0;

    m = 0;
    while (j < n)
    {
        find_max_help(g, n, 1, j, min);
        j++;
    }
}

int main(int argc, char **argv)
{
    int *w;
    int i = 0;
    int nodes = 0;
    int max = 0;
    int min = 0;
    int **g;

    if (argc != 2)
        return (1);
    while (argv[1][i])
    {
        if (i == 0 || argv[1][i - 1] == ' ' || argv[1][i - 1] == '-')
            nodes++;
        i++;
    }
    w = parse(argv[1], nodes, &max, &min);
    printf("%d\n", max);
    printf("%d\n", min);
    g = create_graph(w, max + 1, nodes);
    find_max(g, max, min);
    printf("%d\n", m);
    return (0);
}
