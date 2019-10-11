#include <stdio.h>

	struct s_node {
		int           value;
		struct s_node *right;
		struct s_node *left;
	};

struct s_node *convert_bst(struct s_node *bst);

void print_list(struct s_node *bst)
{
    int i = 0;
    while(i < 10)
    {
        printf("%d ", bst->value);
        bst = bst->left;
        i++;
    }
    printf("\n");
}

int main()
{
    struct s_node *res;
    struct s_node *n0 = NULL;
    struct s_node
    n3 = {3, 0, 0},
    n2 = {2, 0, 0},
    n1 = {1, 0, 0},
    n5 = {5, 0, 0},
    n6 = {6, 0, 0};

    n3.left = &n2;
    n3.right = &n6;
    n2.left = &n1;
    n6.left = &n5;

    res = convert_bst(n0);
    printf("n0 %s\n", (char *)res);
    res = convert_bst(&n3);
    print_list(res); 
    return (0);
}