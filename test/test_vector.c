#include "test_vector.h"
#include <stdio.h>
#include <vector.h>
#include "stu.h"
void add_stus(VECTOR* Vector, const STUDENT* stu) {
    if (stu) {
        printf("------------------\n");
        if (!vector_empty(Vector)) {
            for (VECTOR_ITERATOR* it = vector_begin(Vector); it != vector_end(Vector); ++it) {
                if (stu->age < ((STUDENT*)*it)->age) {
                    it = vector_insert(Vector, stu, it);
                    if (it) print_stu(*it);
                    printf("内插--------------\n");
                    return;
                }
            }
        }
        vector_push(Vector, stu);
        print_stu(vector_back(Vector));
        printf("尾插入---------------\n");
    }
}
void pri_stus(const VECTOR* Vector) {
    if (Vector || vector_size(Vector) > 0) {
        printf("-------开始打印学生列表-------\n");
        for (const VECTOR_ITERATOR* it = vector_begin(Vector); it != vector_end(Vector); ++it) print_stu(*it);
        printf("-------打印学生列表结束-------\n");
    }
}
void test_vector() {
    printf("Vector测试程序！\n");
    printf("------------------------------------\n");
    VECTOR* Vector = vector_new(SIZE_MAX);
    printf("Vector指针位置：%p\n", &Vector);
    printf("Vector->data指针位置：%p\n", Vector->data);
    printf("当前大小：%zu\n", vector_size(Vector));

    STUDENT* stu = stus_set();

    printf("------开始五次插入学生------------------\n");
    for (int i = 0; i < 5; ++i) add_stus(Vector, &stu[i]);
    printf("------结束五次插入学生------------------\n");
    print_stu(vector_front(Vector));
    printf("------------------------------------\n");
    printf("这是Vector地址：%p\n", Vector);
    printf("这是下标0位置数据地址%p\n", vector_at(Vector, 0));
    printf("Vector数据指针位置：%p，数据名字指针位置：%p。\n", vector_at(Vector, 0), ((STUDENT*)vector_at(Vector, 0))->name);
    printf("Vector数据指针位置：%p，数据名字：%s。\n", vector_at(Vector, 0), ((STUDENT*)vector_at(Vector, 0))->name);
    if (!vector_empty(Vector)) printf("Vector数据指针位置：%p\n", vector_at(Vector, 0));
    printf("当前大小：%zu\n", vector_size(Vector));
    printf("------------------------------------\n");
    pri_stus(Vector);
    printf("------------------------------------\n");
    printf("当前大小：%zu\n", vector_size(Vector));
    VECTOR_ITERATOR* v_it = vector_begin(Vector);
    ++v_it;
    v_it = vector_erase(Vector, v_it);
    printf("------------------------------------\n");
    if (v_it) {
        printf("擦除一个学生成功\n");
        print_stu(*v_it);
    } else printf("擦除一个学生失败\n");
    printf("------------------------------------\n");
    printf("查找%s位置在%zu\n", stu[2].name, vector_find(Vector, &stu[2]));
    printf("------------------------------------\n");
    vector_clear(Vector);
    printf("Vector已清理！\n");
    printf("当前大小：%zu\n", vector_size(Vector));
    v_it = vector_begin(Vector);
    vector_insert(Vector, &stu[0], v_it);
    printf("------------------------------------\n");
    pri_stus(Vector);
    printf("------------------------------------\n");
    if (vector_empty(Vector)) printf("为空\n");
    else printf("不为空\n");
    printf("Vector数据指针位置：%p\n", vector_at(Vector, 0));
    printf("------------------------------------\n");
    vector_del(Vector);
    stus_del(stu);
}