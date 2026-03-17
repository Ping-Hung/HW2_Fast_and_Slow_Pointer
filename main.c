#include <stdio.h>
#include <stdlib.h>
#include "list.h"

char *prog_name = "list_creation"

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("usage: ./%s <number of nodes in list>\n", prog_name);
        return EXIT_FAILURE;
    }

    size_t size = atol(argv[1]);
    struct list_node *head = NULL;
#ifndef ALLOCATOR
    /* repeatedly calling malloc */
    list_node = list_create(size);
    list_free_loop(head);
#else
    /* using memory allocator */
#endif
    return EXIT_SUCCESS;
}
