cmake_minimum_required(VERSION 3.10)
project(HW2_linked_list_cache LANGUAGES C)

add_subdirectory(mem_allocator)
add_subdirectory(list)

add_executable(${PROJECT_NAME}
  main.c
)

target_link_libraries(${PROJECT_NAME}
  PRIVATE
  list
  mem_allocator
)
