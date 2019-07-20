#include <stdio.h>

struct s_node 
{
	int value;
	struct s_node *right;
	struct s_node *left;
};

struct s_node *convert_bst(struct s_node *bst);

void print_lst(struct s_node *bst)
{
    struct s_node *t;
    int i = 0;
    t = bst;

    while(i < 12)
    {
        printf("%d ", t->value);
        i++;
        t = t->right;
    }
    printf("\n");
    t = bst;
    i = 0;
    while(i < 12)
    {
        printf("%d ", t->value);
        i++;
        t = t->left;
    }
    printf("\n");
    
}
void print_tree(struct s_node	*root)
{

	if (!root)
		return ;
	printf("%d  ", root->value);
	if (root->left != NULL)
		printf("l %d  ", root->left->value);
	else
		printf("l %d  ", 0);
	if (root->right != NULL)
		printf("r %d\n", root->right->value);
	else
		printf("r %d\n", 0);
	print_tree(root->left);
	print_tree(root->right);
}
void test1()
{
    struct s_node *res;
    struct s_node 
    n5 = {5, 0, 0},
    n2 = {2, 0, 0},
    n7 = {7, 0, 0},
    n1 = {1, 0, 0},
    n3 = {3, 0, 0},
    n6 = {6, 0, 0};

    n7.left = &n6;

    n5.left = &n2;
    n5.right = &n7;

    n2.left = &n1;
    n2.right = &n3;

    print_tree(&n5);
    res = convert_bst(&n5);
    print_lst(res);
}


int main()
{
    test1();
    return (0);
}