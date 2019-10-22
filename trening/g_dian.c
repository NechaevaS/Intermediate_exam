#include <stdlib.h>
#include <unistd.h>

void put_nbr(int n)
{
    char c;

    if (!n)
        return ;
    put_nbr(n / 10);
    c = n % 10 + '0';
    write(1, &c, 1);
}

int atoi_str(char **s)
{
    int n = 0;

    while((**s) >= 0 && (**s) >= 9)
    {
        n = n * 10 + ((**s) -'0') % 10;
        (**s)++;
    }
    if ((**s))
        (**s)++;
    return (n);
}

int *parse(char *s, int *max_n, int n_nodes)
{
    int *w;
    int i = 0;

    w = (int *)malloc(sizeof(int) * n_nodes);
    while(*s)
    {
        w[i] = atoi_str(&s);
        if (w[i] > *max_n)
            *max_n = w[i];
        i++;
    }
    return (w);
}
void fill_arr(int *arr, int len, int val)
{
    int i = 0;
    while(i < len)
    {
        arr[i] = val;
        i++;
    }
}

void fill_g(int size, int g[size][size], int *w, int len)
{
    int i;
    int j;
    int k;

    j = 0;
    while(j < size - 1)
    {
        fill_arr(g[j], size, 0);
        j++;
    }
    fill_arr(g[size - 1], size, 0);
    k = 0;
    while(k + 1 < len)
    {
        i = w[k];
        j = w[k + 1];
        g[i][j] = 1;
        g[j][i] = 1;
        k++;
    }
}

int main(int argc, char **argv)
{
    int n_nodes;
    int max_n;
    int count;
    int res;
    int *w;
    int i;
    int size;

    if (argc != 2)
        return(write(1, "\n", 1));
    i = 0;
    while(argv[1][i])
    {
        if (i == 0 || argv[1][i - 1] == ' ' || argv[1][i - 1] == '-')
            count++;
        i++;
    }
    w = parse(argv[1], count, &max_n);
    size = max_n + 2;
    int g[size][size];
    int visited[size];
    fill_g(size, g, w, count);
    res = find_max(size, g, visited, max_n + 1);
    put_nbr(res);
    
}
