#include <stdio.h>

struct s_node 
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

int	can_split(struct s_node *n);

void test1()
{
    struct s_node 
    n28 = {28, 0, 0},
    n51 = {51, 0, 0},
    n26 = {26, 0, 0},
    n48 = {48, 0, 0},
    n76 = {76, 0, 0},
    n13 = {13, 0, 0};

    n28.left = &n51;

    n51.left = &n26;
    n51.right = &n48;

    n26.left = &n76;
    n26.right = &n13;
    printf("test1 %d\n", can_split(&n28));
}

void test2()
{
    struct s_node 
    n5 = {5, 0, 0},
    n1 = {1, 0, 0},
    n6 = {6, 0, 0},
    n4 = {4, 0, 0},
    n7 = {7, 0, 0},
    n3 = {3, 0, 0},
    n2 = {2, 0, 0},
    n8 = {8, 0, 0};

    n4.right = &n8;

    n5.left = &n1;
    n5.right = &n6;

    n6.left = &n4;
    n6.right = &n7;

    n7.left = &n3;
    n7.right = &n2;
    
    printf("test2 %d\n", can_split(&n5));
}

void test0()
{
    struct s_node *n0 = NULL;
    
    printf("test0 %d\n", can_split(n0));
}

int main()
{
    test0();
    test1();
    test2();
    return (0);
}
