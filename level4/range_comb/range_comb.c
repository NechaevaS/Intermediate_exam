
#include <stdlib.h>


int factorial(int n)
{
    int f = 1;

    while (n > 0)
    {
        f = f * n;
        n--;
    }
    return (f);
}

void traverse(int *w, int n, int curr, int **res, int *pos)
{
    int i = 0;
    if (curr == n)
    {
        res[*pos] = (int *)malloc(sizeof(int) * n);
        while(i < n)
        {
            res[*pos][i] = w[i];
            i++;
        }
        (*pos)++;
        return ;
    }
    while (i < n)
    {
        if (w[i] == -1)
        {
            w[i] = curr;
            traverse(w, n, curr + 1, res, pos);
            w[i] = -1;
        }
        i++;
    }
}

int    **range_comb(int n)
{
    int **res;
    int *w;
    int pos = 0;
    int i = 0;

    if (n <= 0)
        return NULL;
    w = (int *)malloc(sizeof(int) * n);
    while (i < n)
    {
        w[i] = -1;
        i++;
    }
    res = (int **)malloc(sizeof(int *) * factorial(n));
    traverse(w, n, 0, res, &pos);
    free(w);
    return (res);
}
