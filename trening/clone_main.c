#include <stdio.h>

	struct s_node {
		int           data;
		struct s_node *next;
		struct s_node *other;
	};

struct s_node *clone_list(struct s_node *node);

void print_list(struct s_node *n)
{
    while(n)
    {
        printf("n %d,(%p)", n->data, n);
        if (n->other)
            printf(", other(%d, %p)", n->other->data, n->other);
        else
            printf(", other(0, NULL          )");
        if(n->next)
            printf(", next(%d, %p)", n->next->data, n->next);
        else
             printf(", next(0, NULL          )");
        printf("\n");
        n = n->next;
    }
}

int main()
{
    struct s_node *res;
   // struct s_node *n0 = NULL;
    struct s_node *n11 = NULL;
    struct s_node *n13 = NULL;
    struct s_node *n14 = NULL;
    struct s_node
    n1 = {1, 0, 0},
    n2 = {2, 0, 0},
    n3 = {3, 0, 0},
    n4 = {4, 0, 0},
    n5 = {5, 0, 0};

    n11 = &n1;
    n13 = &n5;
    n14 = &n2;
    n1.next = &n2;
    n1.other = n11;
    n2.next = &n3;
    n3.next = &n4;
    n3.other = n13;
    n4.next = &n5;
    n4.other = n14;
    n11 = &n1;
    n13 = &n5;
    n14 = &n2;

    print_list(&n1);
    res = clone_list(&n1);
    print_list(res);
    print_list(&n1);
}