#include <stdio.h>
#include <stdlib.h>
#include "circular_linked_list.h"

static CListNode *clist_create_node(int value)
{
    CListNode *node = malloc(sizeof(*node));
    if (node == NULL) {
        return NULL;
    }
    node->value = value;
    node->next = node; /* a lone node points to itself */
    return node;
}

void clist_init(CList *list)
{
    if (list != NULL) {
        list->tail = NULL;
    }
}

int clist_is_empty(const CList *list)
{
    return list == NULL || list->tail == NULL;
}

int clist_push_front(CList *list, int value)
{
    if (list == NULL) {
        return 0;
    }

    CListNode *node = clist_create_node(value);
    if (node == NULL) {
        return 0;
    }

    if (list->tail == NULL) {
        list->tail = node;
    } else {
        node->next = list->tail->next; /* old head */
        list->tail->next = node;       /* new head */
    }
    return 1;
}

int clist_push_back(CList *list, int value)
{
    if (!clist_push_front(list, value)) {
        return 0;
    }
    /* New node is the head; rotating the tail onto it makes it the last. */
    list->tail = list->tail->next;
    return 1;
}

CListNode *clist_search(const CList *list, int value)
{
    if (clist_is_empty(list)) {
        return NULL;
    }

    CListNode *cur = list->tail->next;
    do {
        if (cur->value == value) {
            return cur;
        }
        cur = cur->next;
    } while (cur != list->tail->next); /* stop when back at the start */

    return NULL;
}

int clist_delete_value(CList *list, int value)
{
    if (clist_is_empty(list)) {
        return 0;
    }

    CListNode *prev = list->tail;
    CListNode *cur = list->tail->next;

    do {
        if (cur->value == value) {
            if (cur == prev) {          /* only node in the list */
                list->tail = NULL;
            } else {
                prev->next = cur->next;
                if (cur == list->tail) {
                    list->tail = prev;
                }
            }
            free(cur);
            return 1;
        }
        prev = cur;
        cur = cur->next;
    } while (prev != list->tail);       /* every node visited once */

    return 0;
}

void clist_print(const CList *list)
{
    if (clist_is_empty(list)) {
        printf("(empty)\n");
        return;
    }

    const CListNode *head = list->tail->next;
    const CListNode *cur = head;
    do {
        printf("%d -> ", cur->value);
        cur = cur->next;
    } while (cur != head);
    printf("(back to %d)\n", head->value);
}

void clist_free(CList *list)
{
    if (clist_is_empty(list)) {
        return;
    }

    CListNode *cur = list->tail->next;
    list->tail->next = NULL;            /* break the circle */
    while (cur != NULL) {
        CListNode *next = cur->next;
        free(cur);
        cur = next;
    }
    list->tail = NULL;
}
