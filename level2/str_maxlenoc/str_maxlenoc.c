/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_maxlenoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 14:02:34 by snechaev          #+#    #+#             */
/*   Updated: 2019/07/30 15:58:44 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>

int ft_strlen(char *s)
{
    int i = 0;
    while(s[i] != '\0')
    {
        i++;
    }
    return (i);
}

void print_str(char *s, int len)
{
    int i = 0;
    while(i < len)
    {
        write(1, &s[i], 1);
        i++;
    }
}
int str_cmp(char *s1, char *s2, int len)
{
    int i = 0;
    while (i < len)
    {
        if (s1[i] != s2[i])
            return(s1[i] - s2[i]);
        else
            i++;
    }
    i--;
    return(s1[i] - s2[i]);
}

char *find_sub(char *sub, char *s, int *l_sub)
{
    int i = 0;
    int len;
    len = ft_strlen(s);
    while(i + *l_sub <= len)
    {
        if(str_cmp(&s[i], sub, *l_sub) == 0)
        {
            return (s + i);
        }
        else
            i++;
    }
    return (NULL);
}

int main(int argc, char **argv)
{
    int all_len;
    int len;
    int i = 0;
    int j;

    if (argc < 2)
    {
        write(1, "\n", 1);
        return (0);
    }
    all_len = ft_strlen(argv[1]);
    len = all_len;

    if (argc == 2)
    {
        write(1, argv[1], len);
        write(1, "\n", 1);
        return (0);
    }
    while (len > 0)
    {
       
        j = 0;
        while(j + len <= all_len)
        {
            i = 2;
            while(i < argc)
            {
                if (find_sub(&argv[1][j], argv[i], &len) != NULL)
                    i++;
                else
                    break; 
            }
            if (i == argc)
            {
                print_str(&argv[1][j], len);
                write(1, "\n", 1);
                return (0);
            }
            j++;
        }
        len--;
    }
    write(1, "\n", 1);
    return (0);
}
