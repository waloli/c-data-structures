#include <stdio.h>
#include "circular_linked_list.h"

int main(void)
{
    CList list;
    clist_init(&list);

    clist_push_back(&list, 10);
    clist_push_back(&list, 20);
    clist_push_front(&list, 5);
    clist_print(&list);

    printf("Found 20: %s\n", clist_search(&list, 20) ? "yes" : "no");
    printf("Found 99: %s\n", clist_search(&list, 99) ? "yes" : "no");

    clist_delete_value(&list, 20);   /* deleting the tail updates tail */
    clist_print(&list);

    clist_free(&list);
    return 0;
}
