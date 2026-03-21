#ifndef __SLAB_ALLOCATOR_INCLUDE_ALLOCATOR_H_
#define __SLAB_ALLOCATOR_INCLUDE_ALLOCATOR_H_

/*
 * Reference:
 * 1. https://github.com/thibault-reigner/userland_slab/blob/master/src/slab.h
 * 2. https://marek.vavrusa.com/memory/
*/

#include <stddef.h>

struct slab_allocator {
    void* base;
    void** head; /* the head of the linked list of the free nodeds */
};

void allocator_init(struct slab_allocator* allocator, size_t obj_size, size_t obj_count);

void *mem_alloc(struct slab_allocator* allocator);

void mem_free(struct slab_allocator* allocator, void *mem);

void allocator_release(struct slab_allocator* allocator);

#endif  //__SLAB_ALLOCATOR_INCLUDE_ALLOCATOR_H_
