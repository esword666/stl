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
        printf("β����---------------\n");
    }
}
static void pri_stus(const STACK* stack) {
    printf("-------��ʼ��ӡѧ���б�-------\n");
    print_stu(stack_top(stack));
    printf("-------��ӡѧ���б����-------\n");
}
void test_stack() {
    printf("Stack���Գ���\n");
    printf("------------------------------------\n");
    STACK* stack = stack_new(sizeof(STUDENT));
    printf("stackָ��λ�ã�%p\n", &stack);
    printf("stack->dataָ��λ�ã�%p\n", stack->data);
    printf("��ǰ��С��%zu\n", stack_size(stack));
    STUDENT* stu = stus_set();
    printf("------��ʼ��β���ѧ��------------------\n");
    for (int i = 0; i < 5; ++i) add_stus(stack, &stu[i]);
    printf("------������β���ѧ��------------------\n");
    pri_stus(stack);
    printf("��ǰ��С��%zu\n", stack_size(stack));
    stack_pop(stack);
    printf("��ǰ��С��%zu\n", stack_size(stack));
    pri_stus(stack);
    VECTOR* vector = vector_new(sizeof(STUDENT));
    stack_copy_vector(stack, vector);
    printf("��ǰ��С��%zu\n", vector_size(vector));
    if (vector || vector_size(vector) > 0) {
        printf("-------��ʼ��ӡѧ���б�-------\n");
        for (const VECTOR_ITERATOR* it = vector_begin(vector); it != vector_end(vector); ++it) {
            print_stu(*it);
        }
        printf("-------��ӡѧ���б����-------\n");
    }
    swap(stack, vector);
    if (vector || vector_size(vector) > 0) {
        printf("-------��ʼ��ӡѧ���б�-------\n");
        for (const VECTOR_ITERATOR* it = vector_begin(vector); it != vector_end(vector); ++it) {
            print_stu(*it);
        }
        printf("-------��ӡѧ���б����-------\n");
    }
    vector_del(vector);
    stack_del(stack);
}