struct s_node
{
	int           value;
	struct s_node *right;
	struct s_node *left;
};

void perimeter(struct s_node *root);

int main()
{
	//struct s_node *n1 = 0;
	struct s_node n1 = {1, 0, 0},
	n2 = {2, 0, 0},
	n3 = {10, 0, 0},
	n4 = {3, 0, 0},
	n5 = {9, 0, 0},
	n6 = {33, 0, 0},
	n7 = {333, 0, 0},
	n8 = {99, 0, 0},
	n9 = {8, 0, 0},
	n10 = {4, 0, 0},
	n11 = {5, 0, 0},
	n12 = {6, 0, 0},
	n13 = {7, 0, 0};

	n1.left = &n2;
	n1.right = &n3;
	n2.left = &n4;
	n4.right = &n6;
	n6.left = &n7;
	n3.right = &n5;
	n5.left = &n8;
	n5.right = &n9;
	n8.right = &n11;
	n8.left = &n10;
	n9.right = &n13;
	n9.left = &n12;

	perimeter(&n1);
	return (0);
}
