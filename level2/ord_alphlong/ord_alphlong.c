/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ord_alphlong.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 09:58:21 by exam              #+#    #+#             */
/*   Updated: 2019/09/24 09:58:23 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ord_alphlong.h"

int is_wsps(char c)
{
    return (c == ' ' || c == '\t');
}

int count_words(char *p)
{
    int count = 0;
    int i = 0;

    while(p[i])
    {
        if ((!is_wsps(p[i]) && i == 0) || (!is_wsps(p[i]) && is_wsps(p[i - 1])))
            count++;
        i++;
    }
    return (count);
}

void fill_arr(t_word *w, char *s)
{
    int i = 0;
    int j = 0;
    int len;

    while (s[i])
    {
        if ((!is_wsps(s[i]) && i == 0) || (!is_wsps(s[i]) && is_wsps(s[i - 1])))
        {
           len = 0;
            w[j].w = &s[i];
            while (!is_wsps(s[i]) && s[i])
            {
                i++;
                len++;
            }
            w[j].len = len;
            j++;
        }
        i++;
    }
}

int str_cmp(char *s1, char *s2)
{
    int i = 0;
    char c1;
    char c2;

    while (s1 && s2)
    {
        if (s1[i] >= 'A' && s1[i] <= 'Z')
            c1 = s1[i] + 32;
        else
            c1 = s1[i];
        if (s2[i] >= 'A' && s2[i] <= 'Z')
            c2 = s2[i] + 32;
        else
            c2 = s2[i];
        if (c1 != c2)
            return (c1 - c2);
        i++;
    }
    return (c1 - c2);
}

int is_less(t_word w1, t_word w2)
{
    if (w1.len < w2.len)
        return (1);
    if (w1.len == w2.len)
    {
        if(str_cmp(w1.w, w2.w) <= 0)
            return (1);
    }
    return(0);

}
void sort_arr(t_word *word, int n_words)
{
    int i = 0;
    int j;
    char *tmp;
    int t;

    while (i < n_words)
    {
        j = i + 1;
        while (j < n_words)
        {
            if (!is_less(word[i], word[j]))
            {
                tmp = word[i].w;
                word[i].w = word[j].w;
                word[j].w = tmp;
                t = word[i].len;
                word[i].len = word[j].len;
                word[j].len = t;
            }
            j++;
        }
        i++;
    }
}

void print_arr(t_word *w, int n_words)
{
    int len;
    int i = 0;
    
    len = w[i].len;
    while (i < n_words)
    {
        write (1, w[i].w, w[i].len);
        if (i + 1 <= n_words && w[i + 1].len == len)
            write (1, " ", 1);
        else
        {
            write (1, "\n", 1);
            len = w[i + 1].len;
        }
        i++;
    }
}

int main (int argc, char **argv)
{
    int n_words;
    t_word  *word;

    if (argc != 2)
    {
        write(1, "\n", 1);
        return (0);
    }
    n_words = count_words(argv[1]);
    word = (t_word*)malloc(sizeof(t_word) * n_words);
    fill_arr(word, argv[1]);
    sort_arr(word, n_words);
    print_arr(word, n_words);
    return (0);
}

