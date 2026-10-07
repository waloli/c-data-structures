#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

typedef struct SListNode {
    int value;
    struct SListNode *next;
} SListNode;

SListNode *slist_create_node(int value);
void slist_push_front(SListNode **head, int value);
void slist_push_back(SListNode **head, int value);
SListNode *slist_search(SListNode *head, int value);
int slist_delete_value(SListNode **head, int value);
void slist_print(const SListNode *head);
void slist_free(SListNode **head);

#endif
