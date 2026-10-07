#include <stdio.h>
#include "arrays.h"

int main(void)
{
    int a[10] = {10, 20, 30, 40};
    int n = 4;

    printf("Initial: ");
    array_print(a, n);

    array_insert(a, &n, 10, 2, 99);
    printf("After insert: ");
    array_print(a, n);

    array_delete(a, &n, 1);
    printf("After delete: ");
    array_print(a, n);

    printf("Index of 99: %d\n", array_search(a, n, 99));
    return 0;
}
