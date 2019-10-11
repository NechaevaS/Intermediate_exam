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

void print(int *s, int n)
{
    int i = 0;
    char c;

    while(i < n)
    {
        c = s[i] + '0';
        write(1, &c, 1);
        i++;
    }
    write(1, "\n", 1);
}

int *create_rev_arr(char *s, int l1, int len)
{
    int i = 0;
    int j;
    int *arr;

    j = l1-1;
    arr = (int *)malloc(sizeof(int) * len);
    zero_arr(arr, len);
    while(i < len && j >= 0)
    {
        arr[i] = (s[j] - '0');
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
    zero_arr(res, len * 2);
    while(i1 < len)
    {
        in_m = 0;
        i2 = 0;
        while(i2 < len)
        {
            mult = a1[i1] * a2[i2];
            in_m = mult / 10;
            pos = i1 + i2;
            res[pos] = res[pos] + (mult % 10);
            if (res[pos] > 9)
            {
                in_m++;
                res[pos] = res[pos] % 10;
            }
            res[pos + 1] = res[pos + 1] + in_m;
            i2++;
        }
        i1++;
    }
    return (res);
}

void print_arr(int *arr, int n, int sign)
{
    int i;
    char c;

    i = n - 1;
    if (sign)
        write (1, "-", 1);
    while (arr[i] == 0)
    {
        i--;
    }
    while (i >= 0)
    {
        c = arr[i] + '0';
        write (1, &c, 1);
        i--;
    }  
}

int main(int argc, char **argv)
{
    int *a1;
    int *a2;
    int l1;
    int l2;
    int len;
    int *mult;
    int sign = 0;
    
    if (argc == 3)
    {
        l1 = str_len(argv[1]);
        l2 = str_len( argv[2]);
        if (argv[1][0] == '-')
        {
            sign = 1;
            l1--;
            argv[1]++;
        }
        if (argv[2][0] == '-')
        {
            sign = 1;
            l2--;
            argv[2]++;
        }
        if (argv[1][0] == '0' || argv[2][0] == '0')
        {
            write (1, "0\n", 2);
            return (0);
        }
        if (l1 > l2)
            len = l1;
        else
            len = l2;
        a1 = create_rev_arr(argv[1], l1, len);
        a2 = create_rev_arr(argv[2], l2, len);
        mult = multipl(a1, a2, len);
        print_arr(mult, len * 2, sign);
    }
    write(1, "\n", 1);
}