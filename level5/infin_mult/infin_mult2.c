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
void zero_arr(int *s, int n)
{
    int i = 0;

    while(i < n)
    {
        s[i] = 0;
        i++;
    }
}

int *create_rev_arr(char *s, int len)
{
    int i = 0;
    int j;
    int *arr;

    j = len-1;
    arr = (int *)malloc(sizeof(int) * len);
    while(i < len)
    {
        if(!s[j])
            arr[i] = 0;
        arr[i] = s[j] - '0';
        i++;
        j--;
    }
    return (arr);
}
int *multipl(int *a1, int *a2, int len)
{
    int in_m;
    int mult;
    int *res;
    int pos;
    int i1 = 0;
    int i2;

    res = (int *)malloc(sizeof(int) * len * 2);
    while(i1 < len)
    {
        i2 = 0;
        while(i2 < len)
        {
            mult = a1[i1] * a2[i2];
            if (in_m)
                mult = mult + in_m;
            if (mult > 9)
                in_m = mult / 10;
            pos = i1 + i2;
            res[pos] = res[pos] + mult % 10;
            i2++;
        }
        i1++;
    }
    return (res);
}

int main(int argc, char **argv)
{
    int *a1;
    int *a2;
    int len;
    int *mult;
    char *res;
    int sign = 0;
    
    if (argc == 3)
    {
        if (str_len(argv[1]) > str_len( argv[2]))
            len = str_len(argv[1]);
        else
            len = str_len(argv[2]);
        if (argv[1][0] == '-' || argv[2][0] == '-')
            sign = 1;
        if (argv[1][0] == '0' || argv[2][0] == 0)
            res = NULL;
        a1 = create_rev_arr(argv[1], len);
        a2 = create_rev_arr(argv[2], len);
        mult = multipl(a1, a2, len);
    }
}