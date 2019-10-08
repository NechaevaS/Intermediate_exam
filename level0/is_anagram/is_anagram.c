/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_anagram.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:25:25 by snechaev          #+#    #+#             */
/*   Updated: 2019/10/07 15:32:25 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_anagram(char *a, char *b)
{
    int arr[126] = {0};
    int i = 0;
    int pos;

    if (!a || !b)
        return (0);
    while (a[i])
    {
        pos = a[i] - 32;
        arr[pos]++;
        i++;
    }
    i = 0;
    while (b[i])
    {
        pos = b[i] - 32;
        arr[pos]--;
        i++;
    }
    i = 0;
    while(i < 126)
    {
        if (arr[i] != 0)
            return (0);
        i++;
    }
    return (1);
}
