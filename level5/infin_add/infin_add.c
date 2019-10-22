/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infin_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 17:20:44 by snechaev          #+#    #+#             */
/*   Updated: 2019/10/21 17:28:48 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int str_len(char *s)
{
    int i = 0;

    while (s[i])
    {
        i++;
    }
    return (i);
}

void fill_arr(int max_len, int len, int arr[max_len], char *s)
{
    int i;
    int j = 0;

    i = len - 1;
    while(j <max_len)
    {
        if(i < 0)
            arr[j] = 0;
        else
            arr[j] = s[i] - '0'; 
        i--;
        j++;
    }
}

void summ(int max_len, int arr1[max_len], int arr2[max_len], int res[max_len])
{
    int in_m = 0;
    int i = 0;
    int sum;

    while(i < max_len)
    {
        sum = arr1[i] + arr2[i] + in_m;
        res[i] = sum % 10;
        in_m = sum / 10;
        i++;
    }
    res[i] = in_m;
}

void diff(int max_len, int arr1[max_len], int arr2[max_len], int res[max_len])
{
    int i = 0;
    int dif;

    while(i < max_len)
    {
        dif = arr1[i] - arr2[i];
        if (dif < 0)
        {
            arr1[i + 1]--;
            dif = dif + 10;
        }
        res[i] = dif;
        i++;
    }
}

void print(int max_len, int res[max_len], int sign)
{
    int i;
    char c;

    i = max_len - 1;
    while(res[i] == 0 && i >= 0)
        i--;
    if(i < 0)
    {
        write(1, "0", 1);
        return;
    }
    if (sign)
        write(1, "-", 1);
    while(i >= 0)
    {
        c = res[i] + '0';
        write(1, &c, 1);
        i--;
    }
}

int main(int argc, char **argv)
{
    int len1;
    int len2;
    int max_len;
    int sign1 = 0;
    int sign2 = 0;

    if (argc == 3)
    {
        len1 = str_len(argv[1]);
        len2 = str_len(argv[2]);
        if (argv[1][0] == '-')
        {
            sign1 = 1;
            len1--;
            argv[1]++;
        }
        if (argv[2][0] == '-')
        {
            sign2 = 1;
            len2--;
            argv[2]++;
        }
        if (len1 > len2)
            max_len = len1 + 1;
        else
            max_len = len2 + 1;
        int arr1[max_len];
        int arr2[max_len];
        int res[max_len];
        fill_arr(max_len, len1, arr1, argv[1]);
        fill_arr(max_len, len2, arr2, argv[2]);
        if (sign1 == sign2)
        {
            summ(max_len, arr1, arr2, res);
            print(max_len, res, sign1);
        }
        else
        {
            if (len1 > len2)
            {
                diff(max_len, arr1, arr2, res);
                print(max_len, res, sign1);
            }
            else
            {
                diff(max_len, arr2, arr1, res);
                print(max_len, res, sign2);
            }
        }    
    }
    write(1, "\n", 1);
    return (0);
}