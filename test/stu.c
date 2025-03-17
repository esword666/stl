#include "stu.h"
#include <stdlib.h>
#include <stdio.h>
STUDENT stu_new(char* name, const int age) {
    return (STUDENT){name, age};
}
void print_stu(const STUDENT* pStu) {
    if (pStu)printf("这是%s，%d岁。\n", pStu->name, pStu->age);
}
STUDENT* stus_set() {
    STUDENT* stus = malloc(sizeof(STUDENT) * 5); // 分配内存
    if (stus) {
        stus[0] = stu_new("Jason", 38);
        stus[1] = stu_new("Marry", 18);
        stus[2] = stu_new("Tom", 28);
        stus[3] = stu_new("Tomy", 48);
        stus[4] = stu_new("Lucy", 8);
    }
    return stus;
}
void stus_del(STUDENT* stus) {
    if (stus)free(stus);
}