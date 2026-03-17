#include <stdlib.h>
#include "list.h"

struct list_node *list_create(size_t size)
{
    /* using pointer-to-pointer, repeatedly calling malloc to build a list of
     * *size* nodes. I.e. malloc is called *size* times.
     * */
    struct list_node *head = NULL;
    for (struct list_node **curr = &head; size != 0; curr = &(*curr)->next) {
        *curr = malloc(sizeof(**curr));
        **curr = (struct list_node) {.value = size; .next = NULL}; 
        size -= 1;
    }
    return head;
}

void list_free_loop(struct list_node *head)
{
    /* walk the list from head to last node, calling free on every node */
    while (head) {
        struct list_node *victim = head;
        head = head->next;
        free(victim);
    }
}
