#include <stddef.h>
#include "stack.h"

void stack_init(Stack *stack)
{
    if (stack != NULL) {
        stack->size = 0;
    }
}

int stack_is_empty(const Stack *stack)
{
    return stack == NULL || stack->size == 0;
}

int stack_is_full(const Stack *stack)
{
    return stack != NULL && stack->size == STACK_CAPACITY;
}

int stack_push(Stack *stack, int value)
{
    if (stack == NULL || stack_is_full(stack)) {
        return 0;
    }

    stack->data[stack->size++] = value;
    return 1;
}

int stack_pop(Stack *stack, int *value)
{
    if (stack == NULL || value == NULL || stack_is_empty(stack)) {
        return 0;
    }

    *value = stack->data[--stack->size];
    return 1;
}

int stack_peek(const Stack *stack, int *value)
{
    if (stack == NULL || value == NULL || stack_is_empty(stack)) {
        return 0;
    }

    *value = stack->data[stack->size - 1];
    return 1;
}
