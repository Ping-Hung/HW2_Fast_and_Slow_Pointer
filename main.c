#include <stdio.h>
#include <stdlib.h>
#include "allocator.h"
#include "list.h"

// #define ALLOCATOR /* uncomment this to test allocator code */

const char *prog_name = "list_creation";
#define LIST_SIZE 10

int main() {
    /* These preprocessor directive are just temporary and can be changed:
     *  - if *ALLOCATOR* symbol is defined in the program, compile the ifdef
     *  code block.
     */
#ifdef ALLOCATOR
    /* using memory allocator */
    struct mem_allocator *allocator = malloc(sizeof(struct mem_allocator)); // is this neccessary?
    struct list_header *list = list_create(allocator, LIST_SIZE);

    struct list_node *head = list->head;
    while (head != NULL) {
      printf("%d  ", head->value);
      head = head->next;
    }
#else
    /* repeatedly calling malloc */
    struct list_node *head = list_create(LIST_SIZE);
    /* maybe do something with the created list */
    list_free_loop(head);
#endif

    return EXIT_SUCCESS;
}
