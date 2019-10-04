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

char *summ_ar(int **w, int v, int h)
{
	int sum = 0;
	int in_m = 0;
	char *res;
	int i;
    int j;

	res = (char *)malloc(sizeof(char) * v + 1);
	i = v - 1;
	res[v] = '\0';
	while (i >=0)
	{
        j = 0;
        while(j < h)
        {
            sum = sum + w[j][i];
            j++;
        }
        if (in_m)
		{
			sum = sum + in_m;
			in_m = 0;
		}
		if (sum > 9)
		{
			in_m = sum / 10;
			res[i] = (sum % 10 + '0');
		}
		else
			res[i] = (sum + '0');
		i--;
	}
	res[i] = in_m + '0';
	return (res);
}

char *mult(char *s1, int len1, char *s2, int len2)
{
    int m;
    int mind;
    char *res;
    int **w;
    int i1 = 0;
    int i2 = 0;
    int j;
    int k;
    w = (int **)malloc(sizeof(int *) * len2);
   
    i2 = len2 - 1;
    j = 0;
    while (i2 >= 0)
    {
        i1 = len1 - 1;
        while(i1 >= 0)
        {
            k = len1 + len2 - 1;
            w[j] = (int **)malloc(sizeof(int *) * (len1 + len2));
            zero_arr(w[j], (len1 + len2));
            m = ((s1[i1] - '0') * (s2[i2] - '0'));
            mind = m / 10;
            w[j][k] = m % 10;
            k--;
            i1--;
        }
        j++;
        i2--;
    }
    res = suum_arr(w, (len1 + len2), len1);

}

int main(int argc, char **argv)
{
    char *s1;
    char *s2;
    int len1;
    int len2;
    char *res;
    int sign = 0;
    
    if (argc == 3)
    {
        s1 = argv[1];
        s2 = argv[2];
        len1 = str_len(s1);
        len2 = str_len(s2);
        if (s1[0] == '-')
        {
            sign = 1;
            len1--;
            s1++;
        }
        if (s2[0] == '-')
        {
            sign = 1;
            len2--;
            s2++;
        }
        if (s1[0] == '0' || s2[0] == 0)
            res = NULL;
        else
        {
        if (len1 > len2)
            res = mult(s1, len1, s2, len2);
        else
            res = mult(s2, len2, s1, len1);

        

        

    }
}