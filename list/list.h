#ifndef __LIST_H__
#define __LIST_H__

#include <stddef.h>

struct slab_allocator;

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

struct list_header *list_create(struct slab_allocator* alloc, size_t size);
void list_free(struct slab_allocator* alloc, struct list_header **list);    /* walk the list from head to last node, freeing each of them */

/* Find middle functions */
struct list_node *find_middle_fast_slow(struct list_node *head);
struct list_node *find_middle_two_scan(struct list_node *head);

#endif  // __LIST_H__
