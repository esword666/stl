#ifndef ALGORITHM_H
#define ALGORITHM_H
#include <stack.h>
#define swap(val_first, val_second) (swap_(val_first, val_second, sizeof(val_first)))
void swap_(void*, void*, size_t);
void stack_rcopy_vector(const STACK* stack, VECTOR* vector);
void stack_copy_vector(const STACK* stack, VECTOR* vector);
#endif