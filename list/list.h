#ifndef __LIST_H__
#define __LIST_H__

#include <stddef.h>

struct mem_allocator;

/* individual nodes of a linked-list */
struct list_node {
    int value;
    struct list_node *next;
};

/* header struct containing the head and tail of the list and its size */
struct list_header {
    struct list_node *head;
    struct list_node *tail;
    size_t size;
};


struct list_header *list_create(struct mem_allocator* alloc, size_t size);
void list_free(struct list_header **list);    /* walk the list from head to last node, freeing each of them */

#endif  // __LIST_H_
