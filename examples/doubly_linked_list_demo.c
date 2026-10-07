#include <stdio.h>
#include "doubly_linked_list.h"

int main(void)
{
    DList list;
    int value;

    dlist_init(&list);

    dlist_push_back(&list, 10);
    dlist_push_back(&list, 20);
    dlist_push_front(&list, 5);

    dlist_print_forward(&list);
    dlist_print_backward(&list);

    dlist_pop_back(&list, &value);   /* O(1) thanks to the tail pointer */
    printf("pop_back -> %d\n", value);
    dlist_print_forward(&list);

    dlist_delete_value(&list, 5);
    dlist_print_forward(&list);

    dlist_free(&list);
    return 0;
}
