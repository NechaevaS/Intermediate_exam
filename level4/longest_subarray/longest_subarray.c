/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_subarray.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 17:33:09 by snechaev          #+#    #+#             */
/*   Updated: 2019/09/23 18:15:40 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

int count_len(char *arr, int i)
{
    int odd = 0;
    int ev = 0;
    int max = 0;

    while(arr[i])
    {
        if (arr[i] % 2 == 0)
            ev++;
        else
            odd++;
        if (ev == odd)
            max = ev + odd;
        i++; 
    }
    return (max);
}

char    *longest_subarray(char *arr)
{
    int tot[strlen(arr)];
    char *res;
    int len;
    int max = 0;
    int i = 0;
    int pos;

    if (!arr)
        return(NULL);
    len = strlen(arr);
    while(i < len)
    {
        tot[i] = count_len(arr, i);
        if(tot[i] > max)
        {
            max = tot[i];
            pos = i;
        }
        i++;
    }
    i = 0;
    res = (char *)malloc(sizeof(char) * max + 1);
    while(i < max)
    {
        res[i] = arr[pos];
        i++;
        pos++;
    }
    res[i] = '\0';
    return (res);
}
