#include <stdio.h>
#include <stddef.h>
#include "arrays.h"

int array_search(const int a[], int n, int value)
{
    for (int i = 0; i < n; i++) {
        if (a[i] == value) {
            return i;
        }
    }
    return -1;
}

int array_insert(int a[], int *n, int capacity, int index, int value)
{
    if (a == NULL || n == NULL || index < 0 || index > *n || *n >= capacity) {
        return 0;
    }

    for (int i = *n; i > index; i--) {
        a[i] = a[i - 1];
    }

    a[index] = value;
    (*n)++;
    return 1;
}

int array_delete(int a[], int *n, int index)
{
    if (a == NULL || n == NULL || index < 0 || index >= *n) {
        return 0;
    }

    for (int i = index; i < *n - 1; i++) {
        a[i] = a[i + 1];
    }

    (*n)--;
    return 1;
}

void array_print(const int a[], int n)
{
    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);
        if (i + 1 < n) {
            printf(" ");
        }
    }
    printf("\n");
}
