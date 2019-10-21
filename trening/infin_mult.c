#include <stdlib.h>
#include <unistd.h>

int str_len(char *s)
{
    int i = 0;
    while(s[i])
    {
        i++;
    }
    return (i);
}

void zero_arr(int len, int *arr)
{
    int i = 0;
    while(i < len)
    {
        arr[i] = 0;
        i++;
    }
}

void parse(char *s, int len, int max, int arr[max])
{
    int i = 0;
    int j = len - 1;

    zero_arr(max, arr);
    while(i < max && j >= 0)
    {
        arr[i] = (s[j] - '0');
        i++;
        j--;
    }
}

void print_arr(int len, int arr[len], int sign1, int sign2)
{
    char c;
    int i;

    if (sign1 || sign2)
    {
        if (sign1 != sign2)
            write(1, "-", 1);
    }
    i = len - 1;
    while(arr[i] == 0)
        i--;
    while(i >= 0)
    {
        c = arr[i] + '0';
        write(1, &c, 1);
        i--;
    }
    write(1, "\n", 1);
}

void mult(int len_res, int len, int arr1[len], int arr2[len], int res[len_res])
{
    int i1 = 0;
    int i2;
    int car = 0;
    int mult;
    int pos;

    zero_arr(len_res, res);
    while(i1 < len)
    {
        car = 0;
        i2 = 0;
        while(i2 < len)
        {
            pos = i1 + i2;
            mult = arr1[i1] * arr2[i2] + car + res[pos];
            res[pos] =  mult % 10;
            car = mult / 10;
            i2++;
        }
        res[pos + 1] = res[pos + 1] + car;
        i1++;
    }
}

int main(int argc, char **argv)
{
    int sign1 = 0;
    int sign2 = 0;
    int len1;
    int len2;
    int len_max;

    if (argc != 3)
        return (write(1, "\n", 1));
    len1 = str_len(argv[1]);
    len2 = str_len(argv[2]);
    if (!len1 || !len2)
        return (write(1, "\n", 1));
    if (argv[1][0] == '0' || argv[2][0] == '0')
    {
        return (write(1, "0\n", 2));
        return (0);
    }
    if (argv[1][0] == '-')
    {
        sign1 = 1;
        argv[1]++;
        len1--;
    }
    if (argv[2][0] == '-')
    {
        sign2 = 1;
        argv[2]++;
        len2--;
    }
    if (len1 > len2)
        len_max = len1;
    else
        len_max = len2;
    int arr1[len_max];
    int arr2[len_max];
    int res[len1 + len2];
    parse(argv[1], len1, len_max, arr1);
    parse(argv[2], len2, len_max, arr2);
    mult(len1 + len2, len_max, arr1, arr2, res);
    print_arr(len1 + len2, res, sign1, sign2);
    return (0);
}