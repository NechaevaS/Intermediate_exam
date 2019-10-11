struct s_node 
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

void count_max(struct s_node *node, int curr, int *max, int pr_val)
{
    if (!node)
        return ;
    if (node->value == pr_val + 1)
        curr++;
    else
        curr = 1;
    if (curr > *max)
        *max = curr;
    count_max(node->left, curr, max, node->value);
    count_max(node->right, curr, max, node->value);
}

int	longest_sequence(struct s_node *node)
{
    int curr = 1;
    int max = 1;
    if (!node)
        return (0);
    if(node->left)
        count_max(node->left, curr, &max, node->value);
    if(node->right)
        count_max(node->right, curr, &max, node->value);
    return (max);
}