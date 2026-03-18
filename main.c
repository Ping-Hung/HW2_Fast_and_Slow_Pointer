#include <stdio.h>
#include <stdlib.h>
#include "list.h"

// #define ALLOCATOR /* uncomment this when doing things with allocator */

char *prog_name = "list_creation"

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("usage: ./%s <number of nodes in list>\n", prog_name);
        return EXIT_FAILURE;
    }

    size_t size = atol(argv[1]);
    struct list_node *head = NULL;
    /* below preprocessor directive are just temporary and can be changed:
     *  - if *ALLOCATOR* symbol is defined in the program, compile the ifdef
     *  code block.
     */
#ifdef ALLOCATOR
    /* using memory allocator */
#else
    /* repeatedly calling malloc */
    list_node = list_create(size);
    list_free_loop(head);
#endif
    return EXIT_SUCCESS;
}
