#ifndef STACK_H
#define STACK_H
#include <vector.h>
typedef VECTOR STACK;
#define stack_new(type) vector_new(type)
#define stack_del(stack) \
    do { \
        if (stack) { \
            _vector_del(stack); \
            stack = NULL; \
        } \
    } while (0)
#define stack_empty(stack) vector_empty(stack)
#define stack_top(stack) vector_back(stack)
#define stack_size(stack) vector_size(stack)
#define stack_clear(stack) vector_clear(stack)
#define stack_pop(stack) vector_pop(stack)
#define stack_push(stack, data) vector_push(stack, data)
#endif