
#include <stdio.h>

int	gold_gain(int **mine, int n);

int main()
{
    
    int a[][3]= {
    {1, 0, 0},
    {0, 3, 4},
    {0, 0, 0}
    };
    int *b[] = {a[0], a[1], a[2]};

    int c[][3]= {
    {1, 2, 3},
    {3, 4, 8},
    {9, 6, 7}
    };
    int *d[] = {c[0], c[1], c[2]};

    int **n = NULL;

    printf("%d\n", gold_gain(b, 3));
    printf("%d\n", gold_gain(d, 3));
    printf("%d\n", gold_gain(n, 3));
    return (0);
}
