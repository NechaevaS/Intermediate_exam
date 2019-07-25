#include <stdio.h>

struct s_node
{
	void *content;
	struct s_node *next;
};

void *intersection(struct s_node *lst1, struct s_node *lst2);

void print_lst(struct s_node *l)
{
    struct s_node *t;

    t = l;

    while(t)
    {
        printf("%d ", (int)(long long)(t->content));
        t = t->next;
    }
    printf("\n");
}
void test1()
{
	struct s_node *res;
    struct s_node
    l11 = {(void *)11, 0},
    l12 = {(void *)12, 0},
    l13 = {(void *)13, 0},
    l14 = {(void *)14, 0},
    l15 = {(void *)15, 0},
    l21 = {(void *)21, 0},
    l22 = {(void *)22, 0};

    l11.next = &l12,
    l12.next = &l13,
    l13.next = &l14,
    l14.next = &l15,

    l21.next = &l22,
    l22.next = &l14,
    print_lst(&l11);
    print_lst(&l21);
    res = intersection(&l11, &l21);
    printf ("test 1 yes %d\n", (int)res->content);
}

void test2()
{
	struct s_node *res;
    struct s_node
    l11 = {(void *)11, 0},
    l12 = {(void *)12, 0},
    l13 = {(void *)13, 0},
    l14 = {(void *)14, 0},
    l15 = {(void *)15, 0},
    l21 = {(void *)21, 0},
    l22 = {(void *)22, 0};

    l11.next = &l12,
    l12.next = &l13,
    l13.next = &l14,
    l14.next = &l15,

    l21.next = &l22;

    print_lst(&l11);
    print_lst(&l21);
	res = intersection(&l11, &l21);
    printf ("test 2 no %d\n", (int)res);
}
struct s_node *k0 = NULL;
void test0()
{
	struct s_node
    l11 = {(void *)11, 0},
    l12 = {(void *)12, 0},
    l13 = {(void *)13, 0},
    l14 = {(void *)14, 0},
    l15 = {(void *)15, 0};

    l11.next = &l12,
    l12.next = &l13,
    l13.next = &l14,
    l14.next = &l15;

	struct s_node *res;
	struct s_node *k0 = NULL;
	res = intersection(k0, &l11);
	printf ("test 0  %d\n", (int)res);
}
int main()
{
    test1();
    test2();
	test0();
    return (0);
}