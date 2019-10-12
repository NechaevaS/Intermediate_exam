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

# include <stdlib.h>
# include <unistd.h>
void put_nbr(int n)
{
    char c;
    if (n == 0)
        return;
    put_nbr(n / 10);
    c = n % 10 + '0';
    write (1, &c, 1); 
}

void print_graph(int n, int g[n][n])
{
    int i = 0;
    int j;
    char c;

    while (i < n)
    {
        j = 0;
        while (j < n)
        {
            c = g[i][j] + '0';
            write(1, &c, 1);
            j++;
        }
        write(1, "\n", 1);
        i++;
    }
}

void fill_arr(int *arr, int n, int val)
{
    int i = 0;

    while(i < n)
    {
        arr[i] = val;
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

void create_graph(int *arr, int size, int g[size][size], int nodes)
{
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < size)
    {
        fill_arr(g[i], size, 0);
        i++;
    }
    fill_arr(g[size - 1], size - 1, 1);

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
//  print_graph(size, g);
}

int find_max(int size, int g[size][size], int j, int visited[size])
{
    int i = 0;
    int cur;
    int m_cur = 0;

    visited[j] = 1;
    while (i < size - 1)
    {
        if (g[j][i] && !visited[i])
        {
            cur = find_max(size, g, i, visited) + 1;
            if (cur > m_cur)
                m_cur = cur;
        }
        i++;
    }
    visited[j] = 0;
    return (m_cur);
}

int main(int argc, char **argv)
{
    int *w;
    int i = 0;
    int nodes = 0;
    int max_node = -1;
    int res;
    int size;
    
    if (argc != 2)
    {
        write(1, "\n" ,1);
        return(1);
    }
    while (argv[1][i])
    {
        if (i == 0 || argv[1][i - 1] == ' ' || argv[1][i - 1] == '-')
            nodes++;
        i++;
    }
    w = parse(argv[1], nodes, &max_node);
    if (max_node == -1)
    {
        write(1, "\n" ,1);
        return(1);
    }
    size = max_node + 2;
    int visited[size];
    int g[size][size];
    create_graph(w, size, g, nodes);
    fill_arr(visited, size, 0);
    res = find_max(size, g, max_node + 1, visited);
    put_nbr(res);
    write(1, "\n", 1);
    return (0);
}
