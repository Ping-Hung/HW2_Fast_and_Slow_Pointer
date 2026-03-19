project(mem_allocator)

add_library(${PROJECT_NAME} bump_allocator.c)

target_include_directories(${PROJECT_NAME}
  PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/
)
