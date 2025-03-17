#include <map.h>
#include <string.h>
#ifdef DEBUG
#include <stdio.h>
#define DEBUG_PRINT(fmt, ...) printf(fmt, ##__VA_ARGS__)
#else
#define DEBUG_PRINT(fmt, ...)
#endif
int cmp_char(const void* key, const RB_NODE* node) {
    return strcmp(key, map_key(node, char));
}
int cmp_void(const void* key, const RB_NODE* node) {
    const void* p_k = map_key(node, void);
    return key < p_k ? -1 : key > p_k ? 1 : 0;
}
int cmp_int(const void* key, const RB_NODE* node) {
    const int key_int = *(int *)key;
    const int p       = *map_key(node, int);
    return key_int < p ? -1 : key_int > p ? 1 : 0;
}
bool less_char(RB_NODE* node_new, const RB_NODE* node_link) {
    return strcmp(map_key(node_new, char), map_key(node_link, char)) < 1;
}
bool less_void(RB_NODE* node_new, const RB_NODE* node_link) {
    return map_key(node_new, void) < map_key(node_link, void);
}
bool less_int(RB_NODE* node_new, const RB_NODE* node_link) {
    return node_new && node_link && *map_key(node_new, int) < *map_key(node_link, int);
}
#define insert_data(pointer, type) (memcpy(malloc(type), (pointer), (type)))
#define erase_data(pointer) do{if ((pointer) != NULL) free(pointer);}while (0)
static MAP_N* map_node_new(const void* key, const size_t key_type, const void* val, const size_t val_type) {
    MAP_N* node = malloc(sizeof(MAP_N));
    if (node != NULL) {
        node->key = insert_data(key, key_type);
        node->val = insert_data(val, val_type);
    }
    return node;
}
static MAP_N* map_node_del(MAP_N* node) {
    erase_data(node->key);
    erase_data(node->val);
    free(node);
    return map_next(node);
}
void map_clear(MAP_R* root) {
    MAP_N* data = map_begin(root);
    while (!map_empty(root)) {
        map_erase(root, data);
        data = map_begin(root);
    }
}
MAP_N* map_erase(MAP_R* root, MAP_N* node) {
    if (root == NULL || node == NULL) return NULL;
    rb_erase_cached((RB_NODE *)node, (RB_ROOT_CACHED_ *)root);
    --root->size;
    DEBUG_PRINT("删除当前节点地址：%p，当前MAP大小为：%zu\n", node, map_size(root));
    return map_node_del(node);
}
MAP_N* map_insert(MAP_R* root, const void* key, const void* val, bool (*less)(RB_NODE*, const RB_NODE*)) {
    if (root == NULL || key == NULL || val == NULL || less == NULL) return NULL;
    MAP_N* node = map_node_new(key, root->key_type, val, root->val_type);
    rb_add_cached((RB_NODE *)node, (RB_ROOT_CACHED_ *)root, less);
    ++root->size;
    DEBUG_PRINT("插入完成，当前MAP大小为：%zu\n当前节点地址：%p\n", map_size(root), node);
    return node;
}