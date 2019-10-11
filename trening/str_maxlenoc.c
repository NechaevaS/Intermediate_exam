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

int sn_cmp(char *s, char *sub, int len)
{
    int i = 0;
    while(i < len)
    {
        if (s[i] != sub[i])
            return (s[i] - sub[i]);
        i++; 
    }
    i--;
    return (s[i] - sub[i]);
}

int check_in(char *s, char *sub, int sub_len)
{
    int i = 0;
    int len;

    len = str_len(s);
    while(i + sub_len <= len)
    {
        if (!sn_cmp(&s[i], sub, sub_len))
            return (1);
        i++;
    }
    return (0);
}

int main(int argc, char **argv)
{
    int len;
    int max_len;
    int i;
    int j;

    if (argc >= 2)
    {
        len = str_len(argv[1]);
        max_len = len;
        while(len > 0)
        {
            i = 0;
            while(i + len <= max_len)
            {
                j = 1;
                while(j < argc)
                {
                    if (!check_in(argv[j], &argv[1][i], len))
                        break;
                    j++;
                }
                if (j == argc)
                {
                    write(1, &argv[1][i], len);
                    write(1, "\n", 1);
                    return (0);
                }
                i++;
            }
            len--;
        }
    }
    write(1, "\n", 1);
    return (0);
}