#include "stack.h"

void push(struct stack* a, int data) {
    NODE* new_node = (NODE*)malloc(sizeof(NODE));
    new_node->data = data;
    new_node->next = NULL;

    if (a->top == NULL) {
        a->top = new_node;
        a->size = 1;
    } else {
        new_node->next = a->top;
        a->top = new_node;
        a->size++;
    }
}

int pop(struct stack* a) {
    int temp = 0;
    NODE* temp_node;

    if (a->top == NULL) {
        printf("Empty Stack!\n");
    } else {
        temp = a->top->data;
        temp_node = a->top;
        a->top = a->top->next;
        free(temp_node);
        a->size--;
    }
    return temp;
}

struct stack* new_stack() {
    struct stack* new_stk = (struct stack*)malloc(sizeof(struct stack));
    new_stk->size = 0;
    new_stk->top = NULL;
    return new_stk;
}

void delete_stack(struct stack* stk) {
    int i;
    NODE* temp;
    if (stk->top != NULL) {
        for (i = 0; i < stk->size; i++) {
            temp = stk->top;
            stk->top = stk->top->next;
            free(temp);
        }
    }
    free(stk);
}