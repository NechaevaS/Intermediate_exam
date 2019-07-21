#include <stdio.h>

	struct s_node {
		int           data;
		struct s_node *next;
		struct s_node *other;
	};

struct s_node *clone_list(struct s_node *node);

void print_lst(struct s_node *l)
{
    struct s_node *t;
    t = l;

    while(t)
    {
        int i = -1;
        if (t->other)
            i = t->other->data;
        printf("%p:%d(%d) ", t, t->data, i);
        t = t->next;
    }
    printf("\n");
}

void test1()
{
    struct s_node *new;
    struct s_node 
    n1 = {1, 0, 0},
    n2 = {2, 0, &n1},
    n3 = {3, 0, 0},
    n4 = {4, 0, 0},
    n5 = {5, 0, 0},
    n6 = {6, 0, &n6};

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;
    n3.other = &n5;

    print_lst(&n1);
    printf("clone start\n");
    new = clone_list(&n1);
    printf("clone fin\n");
    print_lst(&n1);
    print_lst(new);
}


void test0()
{
    struct s_node *new;
    struct s_node *n1 = NULL;

    new = clone_list(n1);
    print_lst(new);

}
int main()
{
    test1();
    test0();

    return (0);
}