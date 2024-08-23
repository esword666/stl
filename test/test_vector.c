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
                    printf("�ڲ�--------------\n");
                    return;
                }
            }
        }
        vector_push(Vector, stu);
        print_stu(vector_back(Vector));
        printf("β����---------------\n");
    }
}
void pri_stus(const VECTOR* Vector) {
    if (Vector || vector_size(Vector) > 0) {
        printf("-------��ʼ��ӡѧ���б�-------\n");
        for (const VECTOR_ITERATOR* it = vector_begin(Vector); it != vector_end(Vector); ++it) print_stu(*it);
        printf("-------��ӡѧ���б����-------\n");
    }
}
void test_vector() {
    printf("Vector���Գ���\n");
    printf("------------------------------------\n");
    VECTOR* Vector = vector_new(SIZE_MAX);
    printf("Vectorָ��λ�ã�%p\n", &Vector);
    printf("Vector->dataָ��λ�ã�%p\n", Vector->data);
    printf("��ǰ��С��%zu\n", vector_size(Vector));

    STUDENT* stu = stus_set();

    printf("------��ʼ��β���ѧ��------------------\n");
    for (int i = 0; i < 5; ++i) add_stus(Vector, &stu[i]);
    printf("------������β���ѧ��------------------\n");
    print_stu(vector_front(Vector));
    printf("------------------------------------\n");
    printf("����Vector��ַ��%p\n", Vector);
    printf("�����±�0λ�����ݵ�ַ%p\n", vector_at(Vector, 0));
    printf("Vector����ָ��λ�ã�%p����������ָ��λ�ã�%p��\n", vector_at(Vector, 0), ((STUDENT*)vector_at(Vector, 0))->name);
    printf("Vector����ָ��λ�ã�%p���������֣�%s��\n", vector_at(Vector, 0), ((STUDENT*)vector_at(Vector, 0))->name);
    if (!vector_empty(Vector)) printf("Vector����ָ��λ�ã�%p\n", vector_at(Vector, 0));
    printf("��ǰ��С��%zu\n", vector_size(Vector));
    printf("------------------------------------\n");
    pri_stus(Vector);
    printf("------------------------------------\n");
    printf("��ǰ��С��%zu\n", vector_size(Vector));
    VECTOR_ITERATOR* v_it = vector_begin(Vector);
    ++v_it;
    v_it = vector_erase(Vector, v_it);
    printf("------------------------------------\n");
    if (v_it) {
        printf("����һ��ѧ���ɹ�\n");
        print_stu(*v_it);
    } else printf("����һ��ѧ��ʧ��\n");
    printf("------------------------------------\n");
    printf("����%sλ����%zu\n", stu[2].name, vector_find(Vector, &stu[2]));
    printf("------------------------------------\n");
    vector_clear(Vector);
    printf("Vector������\n");
    printf("��ǰ��С��%zu\n", vector_size(Vector));
    v_it = vector_begin(Vector);
    vector_insert(Vector, &stu[0], v_it);
    printf("------------------------------------\n");
    pri_stus(Vector);
    printf("------------------------------------\n");
    if (vector_empty(Vector)) printf("Ϊ��\n");
    else printf("��Ϊ��\n");
    printf("Vector����ָ��λ�ã�%p\n", vector_at(Vector, 0));
    printf("------------------------------------\n");
    vector_del(Vector);
    stus_del(stu);
}