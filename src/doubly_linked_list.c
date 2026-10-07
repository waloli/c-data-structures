#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_list.h"

static DListNode *dlist_create_node(int value)
{
    DListNode *node = malloc(sizeof(*node));
    if (node == NULL) {
        return NULL;
    }
    node->value = value;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

void dlist_init(DList *list)
{
    if (list != NULL) {
        list->head = NULL;
        list->tail = NULL;
    }
}

int dlist_push_front(DList *list, int value)
{
    if (list == NULL) {
        return 0;
    }

    DListNode *node = dlist_create_node(value);
    if (node == NULL) {
        return 0;
    }

    node->next = list->head;
    if (list->head != NULL) {
        list->head->prev = node;
    } else {
        list->tail = node;
    }
    list->head = node;
    return 1;
}

int dlist_push_back(DList *list, int value)
{
    if (list == NULL) {
        return 0;
    }

    DListNode *node = dlist_create_node(value);
    if (node == NULL) {
        return 0;
    }

    node->prev = list->tail;
    if (list->tail != NULL) {
        list->tail->next = node;
    } else {
        list->head = node;
    }
    list->tail = node;
    return 1;
}

/* Unlinks a node that belongs to the list and frees it. O(1). */
static void dlist_unlink(DList *list, DListNode *node)
{
    if (node->prev != NULL) {
        node->prev->next = node->next;
    } else {
        list->head = node->next;
    }

    if (node->next != NULL) {
        node->next->prev = node->prev;
    } else {
        list->tail = node->prev;
    }

    free(node);
}

int dlist_pop_front(DList *list, int *value)
{
    if (list == NULL || value == NULL || list->head == NULL) {
        return 0;
    }
    *value = list->head->value;
    dlist_unlink(list, list->head);
    return 1;
}

int dlist_pop_back(DList *list, int *value)
{
    if (list == NULL || value == NULL || list->tail == NULL) {
        return 0;
    }
    *value = list->tail->value;
    dlist_unlink(list, list->tail);
    return 1;
}

int dlist_delete_value(DList *list, int value)
{
    if (list == NULL) {
        return 0;
    }

    for (DListNode *cur = list->head; cur != NULL; cur = cur->next) {
        if (cur->value == value) {
            dlist_unlink(list, cur);
            return 1;
        }
    }
    return 0;
}

void dlist_print_forward(const DList *list)
{
    if (list == NULL) {
        return;
    }
    for (const DListNode *cur = list->head; cur != NULL; cur = cur->next) {
        printf("%d <-> ", cur->value);
    }
    printf("NULL\n");
}

void dlist_print_backward(const DList *list)
{
    if (list == NULL) {
        return;
    }
    for (const DListNode *cur = list->tail; cur != NULL; cur = cur->prev) {
        printf("%d <-> ", cur->value);
    }
    printf("NULL\n");
}

void dlist_free(DList *list)
{
    if (list == NULL) {
        return;
    }

    DListNode *cur = list->head;
    while (cur != NULL) {
        DListNode *next = cur->next;
        free(cur);
        cur = next;
    }
    list->head = NULL;
    list->tail = NULL;
}
