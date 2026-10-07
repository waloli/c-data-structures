#ifndef ARRAYS_H
#define ARRAYS_H

int array_search(const int a[], int n, int value);
int array_insert(int a[], int *n, int capacity, int index, int value);
int array_delete(int a[], int *n, int index);
void array_print(const int a[], int n);

#endif
