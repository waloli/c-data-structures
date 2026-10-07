#ifndef QUEUE_H
#define QUEUE_H

#define QUEUE_CAPACITY 100

typedef struct {
    int data[QUEUE_CAPACITY];
    int front;
    int rear;
    int size;
} Queue;

void queue_init(Queue *queue);
int queue_is_empty(const Queue *queue);
int queue_is_full(const Queue *queue);
int queue_enqueue(Queue *queue, int value);
int queue_dequeue(Queue *queue, int *value);
int queue_front(const Queue *queue, int *value);

#endif
