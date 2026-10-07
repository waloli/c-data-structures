#ifndef CIRCULAR_LINKED_LIST_H
#define CIRCULAR_LINKED_LIST_H

typedef struct CListNode {
    int value;
    struct CListNode *next;
} CListNode;

/*
 * Singly circular list. We store a pointer to the LAST node: the first node
 * is tail->next, so inserting at the front or the back is O(1).
 * An empty list has tail == NULL.
 */
typedef struct {
    CListNode *tail;
} CList;

void clist_init(CList *list);
int clist_is_empty(const CList *list);
int clist_push_front(CList *list, int value);    /* O(1) */
int clist_push_back(CList *list, int value);     /* O(1) */
CListNode *clist_search(const CList *list, int value); /* O(n), one lap max */
int clist_delete_value(CList *list, int value);  /* O(n) */
void clist_print(const CList *list);             /* stops after one lap */
void clist_free(CList *list);

#endif
