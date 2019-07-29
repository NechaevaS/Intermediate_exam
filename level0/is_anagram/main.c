#include <stdio.h>

int	is_anagram(char *a, char *b);

int main()
{
	char *s1 = ".123?.";
	char *s2 = "?321..";
	printf ("%d\n", is_anagram(s1, s2));
	return (0);
}