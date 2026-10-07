#include <stdio.h>
#include <stdlib.h>
#include "singly_linked_list.h"

SListNode *slist_create_node(int value)
{
    SListNode *node = malloc(sizeof(*node));
    if (node == NULL) {
        return NULL;
    }
    node->value = value;
    node->next = NULL;
    return node;
}

void slist_push_front(SListNode **head, int value)
{
    if (head == NULL) {
        return;
    }

    SListNode *node = slist_create_node(value);
    if (node == NULL) {
        return;
    }

    node->next = *head;
    *head = node;
}

void slist_push_back(SListNode **head, int value)
{
    if (head == NULL) {
        return;
    }

    SListNode *node = slist_create_node(value);
    if (node == NULL) {
        return;
    }

    if (*head == NULL) {
        *head = node;
        return;
    }

    SListNode *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = node;
}

SListNode *slist_search(SListNode *head, int value)
{
    while (head != NULL) {
        if (head->value == value) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

int slist_delete_value(SListNode **head, int value)
{
    if (head == NULL || *head == NULL) {
        return 0;
    }

    if ((*head)->value == value) {
        SListNode *tmp = *head;
        *head = (*head)->next;
        free(tmp);
        return 1;
    }

    SListNode *current = *head;
    while (current->next != NULL) {
        if (current->next->value == value) {
            SListNode *tmp = current->next;
            current->next = tmp->next;
            free(tmp);
            return 1;
        }
        current = current->next;
    }

    return 0;
}

void slist_print(const SListNode *head)
{
    while (head != NULL) {
        printf("%d", head->value);
        if (head->next != NULL) {
            printf(" -> ");
        }
        head = head->next;
    }
    printf(" -> NULL\n");
}

void slist_free(SListNode **head)
{
    if (head == NULL) {
        return;
    }

    while (*head != NULL) {
        SListNode *next = (*head)->next;
        free(*head);
        *head = next;
    }
}
