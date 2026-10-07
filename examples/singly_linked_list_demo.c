#include <stdio.h>
#include "singly_linked_list.h"

int main(void)
{
    SListNode *head = NULL;

    slist_push_back(&head, 10);
    slist_push_back(&head, 20);
    slist_push_front(&head, 5);

    slist_print(head);

    slist_delete_value(&head, 20);
    slist_print(head);

    printf("Found 10: %s\n", slist_search(head, 10) ? "yes" : "no");

    slist_free(&head);
    return 0;
}
