
#include <stdio.h>

struct		s_node 
{
	int value;
	struct s_node	*left;
	struct s_node	*right;
};

int	longest_sequence(struct s_node *node);

void test1()
{
    struct s_node a = {10, 0, 0},
    b = {5, 0, 0}, 
    c = {9, 0, 0},
    d = {6, 0, 0},
    e = {7, 0, 0},
    f = {13, 0, 0};

    a.left = &b;
    b.left = &d;
    b.right = &c;
    d.left = &e;
    d.right = &f;
    printf ("test 1 result = %d\n", longest_sequence(&a));
}

void test2()
{
    struct s_node a = {5, 0, 0},
    b = {6, 0, 0}, 
    c = {4, 0, 0},
    d = {9, 0, 0},
    e = {3, 0, 0},
    f = {2, 0, 0},
    j = {3, 0, 0},
    h = {2, 0, 0};
    

    a.left = &b;
    a.right = &c;
    c.left = &d;
    c.right = &e;
    d.left = &j;
    d.right = &f;
    e.right = &h;

    printf ("test 2 result = %d\n", longest_sequence(&a));
}

void test0()
{
    printf ("test 0 result = %d\n", longest_sequence(0));
}

int main()
{
    test0();
    test1();
    test2();
}