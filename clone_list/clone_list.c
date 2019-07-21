
#include <stdlib.h>
    
    struct s_node {
		int           data;
		struct s_node *next;
		struct s_node *other;
	};
void print_lst(struct s_node *l);
struct s_node *clone_list(struct s_node *node)
{
    struct s_node *copy = 0;
    struct s_node *curr;
    struct s_node *elem;
    struct s_node **p;

    if (!node)
        return (0);
    curr = node;
    while (curr)
    {
        elem = (struct s_node *)malloc(sizeof(struct s_node));
        elem->next = curr->next;
        elem->data = curr->data;
        elem->other = 0;
        curr->next = elem;
        curr = elem->next;
    }
    print_lst(node);
    curr = node;
    while (curr)
    {
        if (curr->other)
            curr->next->other = curr->other->next;
        curr = curr->next->next;
    }
    print_lst(node);

    curr = node;
    p = &copy;
    while(curr)
    {
        *p = curr->next;
        p = &(curr->next->next);
        curr->next = curr->next->next;
        curr = curr->next;
    }
    return (copy);
}
