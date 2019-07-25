
#include <stdio.h>

void	print_doublon(int *a, int na, int *b, int nb);

int main()
{
    int a[] = {1,  2, 10, 15};
    int na = 4;
    int b[] = {2, 20, 40, 70};
    int nb = 4;
    print_doublon(a, na, b, nb);
    printf("\n");
    int c[] = {-5,  2, 10, 15, 50, 70, 100, 200, 300, 1200, 5000};
    int nc = 11;
    int d[] = {2,  4,  5,  6,  7, 10,  40,  70};
    int nd = 8;
    print_doublon(c, nc, d, nd);
    printf("\n");
    int e[] = {100,  200, 300};
    int ne = 3;
    int f[] = {1,    2,   3, 4};
    int nf = 4;
    print_doublon(e, ne, f, nf);
}