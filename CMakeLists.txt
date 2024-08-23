cmake_minimum_required(VERSION 3.28)
project(stl C)
set(CMAKE_C_STANDARD 11)
add_library(stl STATIC
        src/container/vector.c
        src/algorithm/rbtree/rbtree.c
        src/container/map.c
        src/algorithm.c
)
target_include_directories(stl PUBLIC include)
enable_testing()
add_executable(test_stl
        test/test.c
        test/test_vector.c
        test/test_map.c
        test/stu.c
        test/test_stack.c)
target_link_libraries(test_stl PRIVATE stl)
add_test(NAME test_stl_run COMMAND test_stl)