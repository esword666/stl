#include <vector.h>
#include <stdio.h>
#include <string.h>
#define DEF_CAPACITY 2
// #define DEBUG
#ifdef DEBUG
#define DEBUG_PRINT(fmt, ...) printf(fmt, ##__VA_ARGS__)
#else
#define DEBUG_PRINT(fmt, ...)
#endif
#define is_full(vector) ((vector)->size == (vector)->capacity)
#define insert_data(pointer, type) (type != SIZE_MAX ? memcpy(malloc(type), (pointer), (type)) : ((void*)pointer))
#define erase_data(pointer, type) if (type != SIZE_MAX) free(pointer)
static int expand(VECTOR* vector) {
    if (is_full(vector)) {
        size_t capacity = vector->capacity;
        capacity += capacity >> 1;
        void** new_data = realloc(vector->data, sizeof(void *) * capacity);
        if (new_data != NULL) {
            vector->data = new_data;
            vector->capacity = capacity;
            DEBUG_PRINT("扩容1.5倍\n");
            return 1;
        }
        DEBUG_PRINT("扩容失败\n");
        return -1;
    }
    DEBUG_PRINT("当前未满\n");
    return 0;
}
void vector_clear(VECTOR* vector) {
    if (!vector_valid(vector)) return;
    if (vector->type == SIZE_MAX) {
        vector->size = 0;
    } else {
        while (!vector_empty(vector)) {
            free(vector->data[--vector->size]);
        }
    }
}
size_t vector_find(const VECTOR* vector, const void* data) {
    if (data != NULL && vector_valid(vector)) {
        for (size_t i = 0; i < vector->size; ++i) {
            if (vector->data[i] == data) {
                DEBUG_PRINT("在位置%zu查找成功\n", i);
                return i;
            }
        }
        DEBUG_PRINT("无匹配数据，查找失败\n");
        return SIZE_MAX;
    }
    DEBUG_PRINT("查找数据无效或Vector无效，查找失败\n");
    return SIZE_MAX;
}
void vector_pop(VECTOR* vector) {
    if (!vector_empty(vector)) {
        void* pop_p = vector->data[--vector->size];
        erase_data(pop_p, vector->type);
        DEBUG_PRINT("尾移出成功\n");
    }
}
void vector_push(VECTOR* vector, const void* data) {
    if (data != NULL && vector_valid(vector) && expand(vector) != -1) {
        vector->data[vector->size++] = insert_data(data, vector->type);
        DEBUG_PRINT("尾插入成功\n");
    }
}
bool vector_resize(VECTOR* vector, const size_t capacity) {
    if (vector_valid(vector) && capacity > vector_size(vector)) {
        void** new_data = realloc(vector->data, sizeof(void *) * capacity);
        if (new_data != NULL) {
            vector->data = new_data;
            vector->capacity = capacity;
            DEBUG_PRINT("调整容量为：%zu\n", capacity);
            return true;
        }
    }
    DEBUG_PRINT("调整容量失败\n");
    return false;
}
VECTOR* vector_new(const size_t type) {
    VECTOR* vector = malloc(sizeof(VECTOR));
    if (vector != NULL) {
        void** data = malloc(sizeof(void *) * DEF_CAPACITY);
        if (data != NULL) {
            DEBUG_PRINT("data分配到位置为%p的内存\n", data);
            vector->data = data;
            vector->size = 0;
            vector->capacity = DEF_CAPACITY;
            vector->type = type;
        } else {
            fprintf(stderr, "内存分配失败\n");
            free(vector);
            vector = NULL;
        }
    }
    return vector;
}
void _vector_del(VECTOR* vector) {
    if (vector_valid(vector)) {
        vector_clear(vector);
        if (vector->type != 0) free(vector->data);
        free(vector);
    }
}
VECTOR_ITERATOR* vector_insert(VECTOR* vector, const void* data, VECTOR_ITERATOR* it) {
    if (data != NULL && vector_valid(vector) && it >= vector_begin(vector) && it <= vector_end(vector)) {
        const size_t index = it - vector->data;
        const size_t elements_to_move = vector->size - index;
        if (is_full(vector)) {
            if (expand(vector) == -1) {
                DEBUG_PRINT("无法扩容，插入失败\n");
                return NULL;
            }
            it = vector->data + index;
        }
        if (index < vector->size++) {
            memmove(it + 1, it, sizeof(void *) * elements_to_move);
        }
        vector->data[index] = insert_data(data, vector->type);
        DEBUG_PRINT("在位置%zu插入成功\n", index);
        return it;
    }
    DEBUG_PRINT("数据无效或Vector无效、迭代器越界，插入失败\n");
    return NULL;
}
VECTOR_ITERATOR* vector_erase(VECTOR* vector, VECTOR_ITERATOR* it) {
    if (vector_valid(vector) && it >= vector_begin(vector) && it < vector_end(vector)) {
        const size_t index = it - vector->data;
        erase_data(*it, vector->type);
        if (index < --vector->size) {
            memmove(it, it + 1, sizeof(void *) * (vector->size - index));
        }
        DEBUG_PRINT("在位置%zu擦除成功\n", index);
        return it;
    }
    DEBUG_PRINT("Vector无效或迭代器越界，擦除失败\n");
    return NULL;
}