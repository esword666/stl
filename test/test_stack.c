#include "test_stack.h"
#include <stdio.h>
#include <stack.h>
#include <algorithm.h>
#include "stu.h"
static void add_stus(STACK* stack, const STUDENT* stu) {
    if (stu) {
        printf("------------------\n");
        stack_push(stack, stu);
        print_stu(stack_top(stack));
        printf("尾插入---------------\n");
    }
}
static void pri_stus(const STACK* stack) {
    printf("-------开始打印学生列表-------\n");
    print_stu(stack_top(stack));
    printf("-------打印学生列表结束-------\n");
}
void test_stack() {
    printf("Stack测试程序！\n");
    printf("------------------------------------\n");
    STACK* stack = stack_new(sizeof(STUDENT));
    printf("stack指针位置：%p\n", &stack);
    printf("stack->data指针位置：%p\n", stack->data);
    printf("当前大小：%zu\n", stack_size(stack));
    STUDENT* stu = stus_set();
    printf("------开始五次插入学生------------------\n");
    for (int i = 0; i < 5; ++i) add_stus(stack, &stu[i]);
    printf("------结束五次插入学生------------------\n");
    pri_stus(stack);
    printf("当前大小：%zu\n", stack_size(stack));
    stack_pop(stack);
    printf("当前大小：%zu\n", stack_size(stack));
    pri_stus(stack);
    VECTOR* vector = vector_new(sizeof(STUDENT));
    stack_copy_vector(stack, vector);
    printf("当前大小：%zu\n", vector_size(vector));
    if (vector || vector_size(vector) > 0) {
        printf("-------开始打印学生列表-------\n");
        for (const VECTOR_ITERATOR* it = vector_begin(vector); it != vector_end(vector); ++it) {
            print_stu(*it);
        }
        printf("-------打印学生列表结束-------\n");
    }
    swap(stack, vector);
    if (vector || vector_size(vector) > 0) {
        printf("-------开始打印学生列表-------\n");
        for (const VECTOR_ITERATOR* it = vector_begin(vector); it != vector_end(vector); ++it) {
            print_stu(*it);
        }
        printf("-------打印学生列表结束-------\n");
    }
    vector_del(vector);
    stack_del(stack);
}