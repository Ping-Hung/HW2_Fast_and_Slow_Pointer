#include <stdio.h>
#include <stdlib.h>

#include "allocator.h"

void allocator_init(struct slab_allocator* allocator, size_t obj_size, size_t obj_count)
{
    if (obj_size < sizeof(void*))
    {
        fprintf(stderr, "slab allocator: do not support the case that obj_size < sizeof(void*)\n");
        exit(EXIT_FAILURE);
    }
    else if (obj_count <= 0)
    {
        fprintf(stderr, "slab allocator: do not support the case that obj_count <= 0\n");
        exit(EXIT_FAILURE);
    }
    allocator->head = (void**)aligned_alloc(64, obj_size * obj_count);
    char *node = (char*)allocator->head;
    for (size_t i = 1; i < obj_count; i++)
    {
        *((void**)node) = node + obj_size;
        node += obj_size;
    }
    *((void**)node) = NULL;
}

void *mem_alloc(struct slab_allocator* allocator)
{
    void* ptr = allocator->head;
    if (ptr == NULL)
    {
        fprintf(stderr, "slab allocator: no more free node\n");
        exit(EXIT_FAILURE);
    }
    allocator->head = *((void**)ptr);
    return ptr;
}

void mem_free(struct slab_allocator* allocator, void *mem)
{
    *((void**)mem) = (void *)allocator->head;
    allocator->head = (void**)mem;
}

