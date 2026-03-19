project(list)

add_library(${PROJECT_NAME}
  list.c
)

target_include_directories(
  ${PROJECT_NAME}
  PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/
  PRIVATE
  ${CMAKE_SOURCE_DIR}/mem_allocator/
)
