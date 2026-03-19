#include <stdlib.h>
#include "allocator.h"

void *mem_alloc(struct mem_allocator* allocator, size_t mem_size) {
  return malloc(mem_size);
}
