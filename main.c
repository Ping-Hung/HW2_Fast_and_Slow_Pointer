#include <stdio.h>
#include <stdlib.h>
#include "allocator.h"
#include "list.h"

const char *prog_name = "list_creation";

int main(int argc, char *argv[]) {
    struct mem_allocator *allocator = malloc(sizeof(struct mem_allocator));
    struct list_header *list = list_create(allocator, 10);

    struct list_node *head = list->head;
    while (head != NULL) {
      printf("%d  ", head->value);
      head = head->next;
    }
//     if (argc != 2) {
//         printf("usage: ./%s <number of nodes in list>\n", prog_name);
//         return EXIT_FAILURE;
//     }
//
//     size_t size = atol(argv[1]);
//     struct list_node *head = NULL;
// #ifndef ALLOCATOR
//     /* repeatedly calling malloc */
//     head = list_create(size);
//     list_free_loop(head);
// #else
//     /* using memory allocator */
// #endif
    return EXIT_SUCCESS;
}
