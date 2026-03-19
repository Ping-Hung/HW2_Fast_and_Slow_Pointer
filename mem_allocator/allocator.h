#ifndef __MEM_ALLOCATOR_INCLUDE_ALLOCATOR_H_
#define __MEM_ALLOCATOR_INCLUDE_ALLOCATOR_H_

#include <stddef.h>

struct mem_allocator {
    size_t total_size;
    size_t remain_size;
    void* head; /* perhaps the base address of the entire block asked from 
                   system memory (I suggest the name base, but head it's okay 😁*/
    void* curr; /* location of available (unused) memory at the moment 
                    curr - head shall denote how much memory is used */
};

void *mem_alloc(struct mem_allocator* allocator, size_t mem_size);

#endif  //__MEM_ALLOCATOR_INCLUDE_ALLOCATOR_H_
