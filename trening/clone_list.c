#include <stdlib.h>
#include <stdio.h>


	struct s_node {
		int           data;
		struct s_node *next;
		struct s_node *other;
	};

void print_list(struct s_node *n);

struct s_node *clone_list(struct s_node *node)
{
    struct s_node *curr;
    struct s_node *res;
    struct s_node *head;
    struct s_node *elem;

    if (!node)
        return (NULL);
    curr = node;
    while(curr)
    {
        elem = (struct s_node *)malloc(sizeof(struct s_node));
        elem->data = curr->data;
        elem->next = curr->next;
        elem->other = NULL;
        curr->next = elem;
        curr = curr->next->next;
    }
    curr = node;
    while(curr)
    {
        if (curr->other)
            curr->next->other = curr->other->next;
        curr = curr->next->next;
    }
    curr = node;
    head = curr->next;
    res = head;
    curr->next = head->next;
    while (head->next)
    {
        curr = head->next;
        head->next = curr->next;
        head = head->next;
        curr->next = head->next;
    }
    return (res);
}