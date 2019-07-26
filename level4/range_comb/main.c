#include <stdio.h>

int    **range_comb(int n);

int main()
{
    int n = 4;
    int i = 0;
    int j = 0;
    int **res;
    int f = factorial(n);

    printf("%d\n", f);
    res = range_comb(n);
    while(i < f)
    {
        j = 0;
        while(j < n)
        {
            printf("%d,", res[i][j]);
            j++;
        }
        printf("\n");
        i++;

    }
    return (0);
}

