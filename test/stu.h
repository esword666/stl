#ifndef STU_H_INCLUDED
#define STU_H_INCLUDED
typedef struct {
    char* name;
    int   age;
}        STUDENT;
STUDENT  stu_new(char*, int);
void     print_stu(const STUDENT*);
STUDENT* stus_set();
void     stus_del(STUDENT*);
#endif