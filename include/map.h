#ifndef MAP_H
#define MAP_H
#include <rbtree_augmented.h>
#include <stdlib.h>
#define map_begin(root) ((root) != NULL ? (MAP_N*)rb_first_cached(root) : NULL)
#define map_end(root) ((root) != NULL ? (MAP_N*)rb_last(&(root)->rb_root) : NULL)
#define map_empty(root) ((root) == NULL || map_size(root) == 0)
#define map_find(root, key, cmp) ((MAP_N*)rb_find((key), &(root)->rb_root, (cmp)))
#define map_new(key_type, val_type) ((MAP_R){{{NULL}, NULL}, (key_type), (val_type), 0})
#define map_next(node) ((MAP_N*)rb_next((RB_NODE*)(node)))
#define map_prev(node) ((MAP_N*)rb_prev((RB_NODE*)(node)))
#define map_key(node,type) ((type*)((MAP_N*)(node))->key)
#define map_val(node,type) ((type*)((MAP_N*)(node))->val)
#define map_size(root) ((root) != NULL ? ((root)->size) : 0)
//#define DEBUG
typedef struct rb_node        RB_NODE;
typedef struct rb_root        RB_ROOT_;
typedef struct rb_root_cached RB_ROOT_CACHED_;
typedef struct {
    struct {
        RB_ROOT_ rb_root;
        RB_NODE* rb_leftmost;
    };
    size_t key_type, val_type, size;
} MAP_R;
typedef struct {
    struct {
        size_t   __rb_parent_color;
        RB_NODE* rb_right;
        RB_NODE* rb_left;
    };
    struct {
        void* key;
        void* val;
    };
}      MAP_N;
int    cmp_char(const void*, const RB_NODE*);
int    cmp_void(const void*, const RB_NODE*);
int    cmp_int(const void*, const RB_NODE*);
bool   less_char(RB_NODE*, const RB_NODE*);
bool   less_void(RB_NODE*, const RB_NODE*);
bool   less_int(RB_NODE*, const RB_NODE*);
void   map_clear(MAP_R*);
MAP_N* map_erase(MAP_R*, MAP_N*);
MAP_N* map_insert(MAP_R*, const void*, const void*, bool (*less)(RB_NODE*, const RB_NODE*));
#endif