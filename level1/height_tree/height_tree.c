	
struct s_node
{
    int				value;
	struct s_node	**nodes;
};

int height_tree(struct s_node *root)
{
    int i = 0;
    int curr;
    int max = 0;
        
    if (!root)
        return (-1);
    if (!root->nodes)
        return (0);
    while(root->nodes[i])
    {
        curr = height_tree(root->nodes[i]);
        if (curr > max)
            max = curr;
        i++;
    }
    return (max + 1);
}
