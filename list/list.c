#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include "allocator.h"

struct list_header *list_create(struct mem_allocator* alloc, size_t size) {
    /* using pointer-to-pointer, repeatedly calling malloc to build a list of
     * *size* nodes. I.e. malloc is called *size* times.
     * */
    struct list_header* new_list = malloc(sizeof(struct list_header));
    *new_list = (struct list_header){.head = NULL, .tail = NULL, .size = 0};

    for (struct list_node **curr = &new_list->head; size != 0; curr = &(*curr)->next) {
        *curr = malloc(sizeof(**curr));
        if (*curr == NULL) {
            fprintf(stderr, "list_create: malloc failed\n");
            exit(EXIT_FAILURE);
        }
        new_list->size++;
        new_list->tail = *curr;
        **curr = (struct list_node) {.value = new_list->size, .next = NULL};
        size -= 1;
    }
    return new_list;
}

void list_free(struct list_header **list) {
    /* walk the list from head to last node, calling free on every node */
    struct list_node *head = (*list)->head;
    while (head) {
        struct list_node *victim = head;
        head = head->next;
        free(victim);
    }
    free(*list);
    *list = NULL;
}
