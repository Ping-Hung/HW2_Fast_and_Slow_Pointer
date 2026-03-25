#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "allocator.h"
#include "list.h"

#define TWO_SCAN /* uncomment this for 2 scan benchmarks */

const char *prog_name = "list_creation";
#define LIST_SIZE 1000000

/* static helper for shuffle */
// static inline void _fisher_yates_shuffle(struct list_node **a_head);

int main() {
    struct slab_allocator allocator = {.head = NULL};
    allocator_init(&allocator, sizeof(struct list_node), LIST_SIZE);
    struct list_header *list = list_create(&allocator, LIST_SIZE);

    /* shuffle the allocated nodes around to mimic real-world allocation
     * (randomized addresses)*/
    struct list_node *head = list->head;
    // _fisher_yates_shuffle(&head); /* this tend to have most cache misses: makes
    //                                  sense due to its "randomized traversal */
#ifdef TWO_SCAN
    printf("The middle is at %p\n", (void *)find_middle_two_scan(head));
#else
    printf("The middle is at %p\n", (void *)find_middle_fast_slow(head));
#endif /* end of TWO_SCAN */
    list_free(&allocator, &list);
    allocator_release(&allocator);
    return EXIT_SUCCESS;
}

// static inline void _fisher_yates_shuffle(struct list_node **a_head)
// {
//     /* source: https://hackmd.io/@sysprog/c-linked-list?stext=64508%3A842%3A0%3A1774105843%3AeZZpmd */
//     srand(time(NULL));
// 
//     // First, we have to know how long is the linked list
//     int len = 0;
//     struct list_node **indirect = a_head;
//     while (*indirect) {
//         len++;
//         indirect = &(*indirect)->next;
//     }   
// 
//     // Append shuffling result to another linked list
//     struct list_node *new = NULL;
//     struct list_node **new_head = &new;
//     struct list_node **new_tail = &new;
// 
//     while (len) {
//         int random = rand() % len;
//         indirect = a_head;
// 
//         while (random--)
//             indirect = &(*indirect)->next;
// 
//         struct list_node *tmp = *indirect;
//         *indirect = (*indirect)->next;
// 
//         tmp->next = NULL;
//         if (new) {
//             (*new_tail)->next = tmp;
//             new_tail = &(*new_tail)->next;
//         } else {
//             new = tmp;
//         }
// 
//         len--;
//     }   
// 
//     *a_head = *new_head;
// }
