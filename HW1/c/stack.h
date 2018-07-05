#ifndef __STACK_H__
#define __STACK_H__

#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

typedef struct node {
    int data;
    struct node* next;
} NODE;

struct stack {
    NODE* top;
    int size;
};

extern void push(struct stack* a, int x);
extern int pop(struct stack* a);
extern struct stack* new_stack();
extern void delete_stack(struct stack* stk);

#endif