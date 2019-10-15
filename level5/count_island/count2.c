#include "count_island.h"

int valid(int h, int w, char *arr, char work[h][w])
{
    int i;
    int j;
    char e;

    j = 0;
    while (j < h)
    {
        i = 0;
        while (i < w - 1)
        {
            e = arr[j * w + i];
            if (e != '.' && e != 'X')
                return (0);
            work[j][i] = e;
            i++;
        }
        if (arr[j * w + w - 1] != '\n')
            return (0);
        work[j][w - 1] = '\n';
        j++;
    }
    return (1);
}

void print(int h, int w, char arr[][w])
{
    int j;

    j = 0;
    while (j < h)
    {
        write(1, arr[j], w);
        j++;
    }
}

int flood(int h, int w, char work[h][w], int num, int j, int i)
{
    if (j >= h || j < 0 || i >= w || i < 0)
        return (0);
    if (work[j][i] != 'X')
        return (0);
    work[j][i] = num + '0';
    flood(h, w, work, num, j, i + 1);
    flood(h, w, work, num, j, i - 1);
    flood(h, w, work, num, j + 1, i);
    flood(h, w, work, num, j - 1, i);
    return (1);
}


int main(int argc, char **argv)
{
    int fd;
    char arr[1024 * 1024];
    int num = 0;
    int n_read;
    int w;
    int h;
    int i;
    int j;

    if (argc != 2)
        return (write(1, "\n", 1));
    fd = open(argv[1], O_RDONLY);
    if (!fd)
        return (write(1, "\n", 1));

    n_read = read(fd, arr, 1024 * 1024);
    if (n_read <= 0)
        return (write(1, "\n", 1));
    w = 0;
    while (arr[w] != '\n')
        w++;
    w++;
    if (w <= 1)
        return (write(1, "\n", 1));
    h = n_read / w;
    char work[h][w];
    if (!valid(h, w, arr, work))
        return (write(1, "\n", 1));
    
    j = 0;
    while(j < h)
    {
        i = 0;
        while (i < w)
        {
            if (flood(h, w, work, num, j, i))
                num++;
            i++;
        }
        j++;
    }
    print(h, w, work);
    return (0);
}