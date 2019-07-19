
#include <stdio.h>

struct s_node 
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

int	width_tree(struct s_node *n);

void test1()
{
    struct s_node
    n1 = {1, 0, 0},
    n2 = {2, 0, 0},
    n3 = {3, 0, 0},
    n4 = {4, 0, 0},
    n5 = {5, 0, 0},
    n6 = {6, 0, 0},
    n7 = {7, 0, 0},
    n8 = {8, 0, 0};

    n1.left = &n2;
    n1.right = &n5;

    n2.left = &n3;
    n2.right = &n4;

    n4.left = &n6;

    n5.left = &n7;
    n5.right = &n8;
    printf("%d\n", width_tree(&n1));
}

void test2()
{
    struct s_node
    n1 = {1, 0, 0},
    n2 = {2, 0, 0},
    n3 = {3, 0, 0},
    n4 = {4, 0, 0},
    n5 = {5, 0, 0},
    n6 = {6, 0, 0},
    n7 = {7, 0, 0},
    n8 = {8, 0, 0},
    n9 = {8, 0, 0},
    n10 = {8, 0, 0},
    n11 = {8, 0, 0},
    n12 = {8, 0, 0},
    n13 = {8, 0, 0};

    n1.left = &n2;
    n1.right = &n3;

    n2.left = &n4;
    n2.right = &n7;

    n4.left = &n5;
    n4.right = &n6;

    n5.right = &n8;

    n7.left = &n9;
    n7.right = &n10;

    n9.left = &n11;
    n9.right = &n12;

    n10.right = &n13;

    printf("%d\n", width_tree(&n1));
}

void test0()
{
    struct s_node *n = NULL;
    printf("%d\n", width_tree(n));
}

int main()
{
    test1();
    test2();
    test0();
    return (0);
}