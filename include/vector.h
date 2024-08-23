#ifndef VECTOR_H
#define VECTOR_H
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#define vector_valid(vector) ((vector) != NULL && (vector)->data != NULL)
#define vector_at(vector, index) ((vector) != NULL && (index) < (vector)->size ? (vector)->data[(index)] : NULL)
#define vector_empty(vector) ((vector) == NULL || (vector)->size == 0)
#define vector_back(vector) (vector_empty(vector) ? NULL : (vector)->data[(vector)->size - 1])
#define vector_front(vector) (vector_empty(vector) ? NULL : (vector)->data[0])
#define vector_size(vector) ((vector) != NULL ? (vector)->size : 0)
#define vector_begin(vector) (vector_valid(vector) ? (vector)->data : NULL)
#define vector_end(vector) (vector_valid(vector) ? (vector)->data + (vector)->size : NULL)
#define vector_capacity(vector) ((vector) != NULL ? (vector)->capacity : 0)
typedef void* VECTOR_ITERATOR;
typedef struct {
    void** data;
    size_t size, capacity, type;
} VECTOR;
VECTOR* vector_new(size_t);
void _vector_del(VECTOR*);
#define vector_del(vector) \
    do { \
        if (vector) { \
            _vector_del(vector); \
            vector = NULL; \
        } \
    } while (0)
void vector_clear(VECTOR*);
size_t vector_find(const VECTOR*, const void*);
void vector_pop(VECTOR*);
void vector_push(VECTOR*, const void*);
bool vector_resize(VECTOR*, size_t);
VECTOR_ITERATOR* vector_erase(VECTOR*, VECTOR_ITERATOR*);
VECTOR_ITERATOR* vector_insert(VECTOR*, const void*, VECTOR_ITERATOR*);
#endif