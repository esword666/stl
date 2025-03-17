#include "test_map.h"
#include <map.h>
#include <stdio.h>
#include "stu.h"
static void add_stus(MAP_R* map_r, const STUDENT* stu) {
    if (stu != NULL) {
        printf("------------------\n");
        print_stu(map_val(map_insert(map_r, stu->name, stu, less_char), STUDENT));
        printf("------------------\n");
    }
}
static void pri_stus(const MAP_R* map_r) {
    printf("------------------\n");
    MAP_N* node = map_begin(map_r);
    while (node) {
        print_stu(map_val(node, STUDENT));
        node = map_next(node);
    }
    printf("------------------\n");
}
void test_map() {
    printf("map测试程序\n");
    printf("------------------------------------\n");
    const STUDENT* stu   = stus_set();
    MAP_R    map_r = map_new(sizeof(char)*20, sizeof(STUDENT));
    printf("------------------------------------\n");
    for (int i = 0; i < 5; i++) add_stus(&map_r, &stu[i]);
    printf("------------------------------------\n");
    pri_stus(&map_r);
    printf("map首数据是%s:%d岁\n", (map_val(map_begin(&map_r), STUDENT))->name, (map_val(map_begin(&map_r), STUDENT))->age);
    print_stu(map_val(map_find(&map_r, "Tomy", cmp_char), STUDENT));
    const char* erase = "Tom";
    printf("删除学生%s后，返回：%d岁\n", erase, (map_val(map_erase(&map_r, map_find(&map_r, erase, cmp_char)), STUDENT))->age);
    pri_stus(&map_r);
}