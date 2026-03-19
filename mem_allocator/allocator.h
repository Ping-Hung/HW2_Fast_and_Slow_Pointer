#ifndef __MEM_ALLOCATOR_INCLUDE_ALLOCATOR_H_
#define __MEM_ALLOCATOR_INCLUDE_ALLOCATOR_H_

#include <stddef.h>

struct mem_allocator {
    size_t total_size;
    size_t remain_size;
    void* head;
    void* curr;
};

void *mem_alloc(struct mem_allocator* allocator, size_t mem_size);

#endif  //__MEM_ALLOCATOR_INCLUDE_ALLOCATOR_H_
