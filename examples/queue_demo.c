#include <stdio.h>
#include "queue.h"

int main(void)
{
    Queue queue;
    int value;

    queue_init(&queue);
    queue_enqueue(&queue, 10);
    queue_enqueue(&queue, 20);
    queue_enqueue(&queue, 30);

    queue_front(&queue, &value);
    printf("Front: %d\n", value);

    while (!queue_is_empty(&queue)) {
        queue_dequeue(&queue, &value);
        printf("Dequeue: %d\n", value);
    }

    return 0;
}
