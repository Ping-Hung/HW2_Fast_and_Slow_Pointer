#ifndef __LIST_H__
#define __LIST_H__

/* individual nodes of a linked-list */
struct list_node {
    int value;
    struct list_node *next;
};

/* header struct containing the head and tail of the list and its size */
struct list_header {
    struct list_node *head, *tail;
    size_t size;
};

/* linked-list functions */
struct list_node *list_create(size_t size);
void list_free_loop(struct list_node *head);    /* walk the list from head to last node, freeing each of them */

/* list_header functions */

#endif
