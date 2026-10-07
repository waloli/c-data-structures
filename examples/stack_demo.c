#include <stdio.h>
#include "stack.h"

int main(void)
{
    Stack stack;
    int value;

    stack_init(&stack);
    stack_push(&stack, 10);
    stack_push(&stack, 20);
    stack_push(&stack, 30);

    stack_peek(&stack, &value);
    printf("Top: %d\n", value);

    while (!stack_is_empty(&stack)) {
        stack_pop(&stack, &value);
        printf("Pop: %d\n", value);
    }

    return 0;
}
