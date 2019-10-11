#include <stdio.h>
struct s_node 
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

int	longest_sequence(struct s_node *node);

int main()
{
    int res;
    struct s_node *n0 = NULL;
    struct s_node
    n1 = {1, 0, 0},
    n2 = {2, 0, 0},
    n3 = {3, 0, 0},
    n4 = {4, 0, 0},
    n5 = {5, 0, 0},
    n6 = {6, 0, 0},
    n7 = {9, 0, 0};

    n1.left = &n2;
    n1.right = &n4;
    n2.right = &n3;
    n4.right = &n5;
    n5.right = &n6;
    n6.left = &n7;

    res = longest_sequence(n0);
    printf("n0 %d\n", res);
    res = longest_sequence(&n1);
    printf("n1 %d\n", res);

    return (0);
}
