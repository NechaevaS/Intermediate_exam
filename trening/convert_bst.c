	struct s_node {
		int           value;
		struct s_node *right;
		struct s_node *left;
	};

struct s_node *find_min(struct s_node *bst)
{
    while(bst->left)
        bst = bst->left;
    return (bst);
}

struct s_node *find_max(struct s_node *bst)
{
    while(bst->right)
        bst = bst->right;
    return (bst);
} 
    void traverce(struct s_node *bst, struct s_node *min, struct s_node *max)
    {
        static struct s_node *cur;

        if (!bst)
            return;
        if (bst != min)
            traverce(bst->left, min, max);
        if (cur)
        {
            bst->left = cur;
            cur->right = bst;
        }
        cur = bst;
        if (bst != max)
            traverce(bst->right, min, max);
    }

    struct s_node *convert_bst(struct s_node *bst)
    {
        struct s_node *max;
        struct s_node *min;

        if (!bst)
            return (0);
        max = find_max(bst);
        min = find_min(bst);
        min->left = max;
        max->right = min;
        traverce(bst, min, max);
        return (min);
    }
