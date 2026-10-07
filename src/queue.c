#include <stddef.h>
#include "queue.h"

void queue_init(Queue *queue)
{
    if (queue != NULL) {
        queue->front = 0;
        queue->rear = 0;
        queue->size = 0;
    }
}

int queue_is_empty(const Queue *queue)
{
    return queue == NULL || queue->size == 0;
}

int queue_is_full(const Queue *queue)
{
    return queue != NULL && queue->size == QUEUE_CAPACITY;
}

int queue_enqueue(Queue *queue, int value)
{
    if (queue == NULL || queue_is_full(queue)) {
        return 0;
    }

    queue->data[queue->rear] = value;
    queue->rear = (queue->rear + 1) % QUEUE_CAPACITY;
    queue->size++;
    return 1;
}

int queue_dequeue(Queue *queue, int *value)
{
    if (queue == NULL || value == NULL || queue_is_empty(queue)) {
        return 0;
    }

    *value = queue->data[queue->front];
    queue->front = (queue->front + 1) % QUEUE_CAPACITY;
    queue->size--;
    return 1;
}

int queue_front(const Queue *queue, int *value)
{
    if (queue == NULL || value == NULL || queue_is_empty(queue)) {
        return 0;
    }

    *value = queue->data[queue->front];
    return 1;
}
