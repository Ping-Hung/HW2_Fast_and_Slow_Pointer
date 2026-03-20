#include <stdio.h>
#include <stdlib.h>
#include "allocator.h"
#include "list.h"

#define ALLOCATOR /* uncomment this to test allocator code */

const char *prog_name = "list_creation";
#define LIST_SIZE 10

int main() {
    /* These preprocessor directive are just temporary and can be changed:
     *  - if *ALLOCATOR* symbol is defined in the program, compile the ifdef
     *  code block.
     */
#ifdef ALLOCATOR
    /* using memory allocator */
    struct slab_allocator allocator = {.head = NULL};
    allocator_init(&allocator, sizeof(struct list_node), LIST_SIZE);
    struct list_header *list = list_create(&allocator, LIST_SIZE);

    struct list_node *head = list->head;
    while (head != NULL) {
      printf("%d  ", head->value);
      head = head->next;
    }
    list_free(&allocator, &list);
#else
    /* repeatedly calling malloc */
    struct list_node *head = list_create(LIST_SIZE);
    /* maybe do something with the created list */
    list_free_loop(head);
#endif

    return EXIT_SUCCESS;
}
