#ifndef SORT_H
#define SORT_H

#include <stddef.h>

void merge_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void merge_sort_helper(int *array, size_t size, int *new_array);
void merge(int *array, size_t size, int *new_array, int middle);

#endif /* SORT_H */
