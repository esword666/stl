cmake_minimum_required(VERSION 3.28)
project(stl C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -O2")

# 静态库
add_library(stl STATIC
        src/container/vector.c
        src/algorithm/rbtree/rbtree.c
        src/container/map.c
        src/algorithm.c
)
target_include_directories(stl PUBLIC include)

# 测试
enable_testing()

# 测试可执行文件
add_executable(test_stl
        test/test.c
        test/test_vector.c
        test/test_map.c
        test/stu.c
        test/test_stack.c
)
target_link_libraries(test_stl PRIVATE stl)

# 添加测试
add_test(NAME test_stl_run COMMAND test_stl)

# 安装规则（可选）
install(TARGETS stl DESTINATION lib)
install(DIRECTORY include/ DESTINATION include)