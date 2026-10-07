#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

typedef struct DListNode {
    int value;
    struct DListNode *prev;
    struct DListNode *next;
} DListNode;

/* The list keeps both ends, so head AND tail operations are O(1). */
typedef struct {
    DListNode *head;
    DListNode *tail;
} DList;

void dlist_init(DList *list);
int dlist_push_front(DList *list, int value);   /* O(1) */
int dlist_push_back(DList *list, int value);    /* O(1) */
int dlist_pop_front(DList *list, int *value);   /* O(1) */
int dlist_pop_back(DList *list, int *value);    /* O(1) */
int dlist_delete_value(DList *list, int value); /* O(n) search, O(1) unlink */
void dlist_print_forward(const DList *list);
void dlist_print_backward(const DList *list);   /* O(n), no tail walk needed */
void dlist_free(DList *list);

#endif
