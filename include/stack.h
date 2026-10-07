#ifndef STACK_H
#define STACK_H

#define STACK_CAPACITY 100

typedef struct {
    int data[STACK_CAPACITY];
    int size;
} Stack;

void stack_init(Stack *stack);
int stack_is_empty(const Stack *stack);
int stack_is_full(const Stack *stack);
int stack_push(Stack *stack, int value);
int stack_pop(Stack *stack, int *value);
int stack_peek(const Stack *stack, int *value);

#endif
