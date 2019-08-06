#include <stdio.h>

struct s_node
{
    int				value;
	struct s_node	**nodes;
};

int height_tree(struct s_node *root);

int main()
{
    struct s_node *n1c[] = {0, 0, 0, 0};
    struct s_node *n3c[] = {0, 0, 0};
    struct s_node *n4c[] = {0, 0};
    struct s_node *n41c[] = {0, 0};
    struct s_node *n42c[] = {0, 0};

    struct s_node
    n1 = {1, n1c},
    n2 = {2, 0},
    n3 = {3, n3c},
    n4 = {4, n4c},
    n31 = {31, 0},
    n32 = {32, 0},
    n41 = {41, n41c},
    n42 = {42, n42c},
    n43 = {42, 0};

    n1.nodes[0] = &n2;
    n1.nodes[1] = &n3;
    n1.nodes[2] = &n4;

    n3.nodes[0] = &n31;
    n3.nodes[1] = &n32;

    n4.nodes[0] = &n41;

    n41.nodes[0] = &n42;

    n42.nodes[0] = &n43;

    printf("%d\n", height_tree(&n1));
}