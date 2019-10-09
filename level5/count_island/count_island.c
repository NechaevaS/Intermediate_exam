/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_island.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 11:15:47 by exam              #+#    #+#             */
/*   Updated: 2019/10/08 17:52:48 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "count_island.h"

int find_len(char *w)
{
    int i = 0;
    while(i < 1024)
    {
        if (w[i] == '\n')
            break;
        i++;
    }
    return (i + 1);
}

t_map *init_map(int len)
{
    t_map *map;

    map = (t_map *)malloc(sizeof(t_map));
    map->h = 0;
    map->w = len;
    map->num_is = 0;
    map->m = (char **)malloc(sizeof(char *) * 1024);
    return (map);
}

int check_map(t_map *map)
{
    int i;
    int j = 0;

    while(j < map->h)
    {
        i = 0;
        while(i < map->w)
        {
            if ((map->m[j][i] == '.' || map->m[j][i] == 'X' ||
                map->m[j][i] == '\n') && map->m[j][map->w - 1] == '\n')
                i++;
            else
            {
                write(1, "\n", 1);
                return (0);
            }
        }
        j++;
    }
    return (1);
}

void print_map(t_map *map)
{
    int i;
    int j = 0;

    while(j < map->h)
    {
        i = 0;
        while(i < map->w)
        {
            write(1, &map->m[j][i], 1);
            i++;
        }
        j++;
    }
}

void  fill(t_map *map, int x, int y)
{
    int new_x;
    int new_y;
    
    if (x >= map->w || x < 0 || y >= map->h || y < 0)
        return;
    if (map->m[y][x] != 'X')
        return ;
    map->m[y][x] = map->num_is + '0';
    new_x = x + 1;
    new_y = y;
    fill(map, new_x, new_y);

    new_x = x - 1;
    new_y = y;
    fill(map, new_x, new_y);

    new_x = x;
    new_y = y + 1;
    fill(map, new_x, new_y);

    new_x = x;
    new_y = y - 1;
    fill(map, new_x, new_y);
}

void  flood_fill(t_map *map)
{
    int i;
    int j = 0;

    if (!map)
        return;
    while(j < map->h)
    {
        i = 0;
        while(i < map->w)
        {
            if (map->m[j][i] == 'X')
            {
              fill(map, i, j);
              map->num_is++;
            }
            i++;
        }
        j++;
    }  
}

int main(int argc, char **argv)
{
    t_map *map;
    int res;
    int fd;
    int len;
    int i = 0;

    if (argc != 2)
    {
        write(1, "\n", 1);
        return(-1);
    }
    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        write(1, "\n", 1);
        return (1);
    }
    char w[1024] = {0}; 
    res = read(fd, w, 1024);
    len = find_len(w);
    close(fd);
    fd = open(argv[1], O_RDONLY);
    map = init_map(len);
    map->m[i] = (char *)malloc(sizeof(char) * len);
    res = 0;
    while((res = read(fd, map->m[i], len)) > 0)
    {
        map->m[i + 1] = (char *)malloc(sizeof(char) * len);
        i++;
    }
    map->h = i;
    if(check_map(map) == 0)
        return (1);
    flood_fill(map);
    print_map(map);
    close(fd);
    return (0);
}

