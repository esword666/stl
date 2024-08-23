#include <algorithm.h>
#include <string.h>
void swap_(void* val_first, void* val_second, const size_t type_size) {
	if (val_first != NULL && val_first != val_second && type_size != 0) {
		switch (type_size) {
			case sizeof(char):
				char tmp_char = *(char*)val_first;
				*(char*)val_first = *(char*)val_second;
				*(char*)val_second = tmp_char;
			break;
			case sizeof(short int):
				short int tmp_short = *(short int*)val_first;
				*(short int*)val_first = *(short int*)val_second;
				*(short int*)val_second = tmp_short;
			break;
			case sizeof(int):
				int tmp_int = *(int*)val_first;
				*(int*)val_first = *(int*)val_second;
				*(int*)val_second = tmp_int;
			break;
			case sizeof(long long):
				long long tmp_long = *(long long*)val_first;
				*(long long*)val_first = *(long long*)val_second;
				*(long long*)val_second = tmp_long;
			break;
			default:
				void* tmp_void =malloc(type_size);
				if (tmp_void != NULL) {
					memcpy(tmp_void, val_first, type_size);
					memcpy(val_first, val_second, type_size);
					memcpy(val_second, tmp_void, type_size);
					free(tmp_void);
				}
		}
	}
}
void stack_rcopy_vector(const STACK* stack, VECTOR* vector) {
	size_t size = stack_size(stack);
	if (size > 0) {
		vector_clear(vector);
		vector->type = stack->type;
		if (vector_resize(vector, size)) {
			for (size_t i = 0; i < size; ++i) vector_push(vector, stack->data[i]);
		}
	}
}
void stack_copy_vector(const STACK* stack, VECTOR* vector)
{
	size_t size = stack_size(stack);
	if (size > 0) {
		vector_clear(vector);
		vector->type = stack->type;
		if (vector_resize(vector, size)) {
			for (size_t i = 0; i < size; ++i) vector_push(vector, stack->data[size - 1 - i]);
		}
	}
}