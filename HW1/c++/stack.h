#ifndef __STACK_H__
#define __STACK_H__

#include <iostream>
using namespace std;

typedef struct node {
    int data;
    struct node* next;
} NODE;

class Stack {
    NODE* top;
    int size;

public:
    Stack() {
        top = NULL;
        size = 0;
    }

    ~Stack() {
        if (top != NULL) {
            NODE *temp;
            for (int i = 0; i < size; i++) {
                temp = top;
                top = top->next;
                delete temp;
            }
        }
    }

    void push(int data) {
        NODE* new_node = new NODE;
        new_node->data = data;
        new_node->next = NULL;

        if (top == NULL) {
            top = new_node;
            size = 1;
        } else {
            new_node->next = top;
            top = new_node;
            size++;
        }
    }

    int pop() {
        int temp = 0;
        NODE* temp_node;

        if (top == NULL) {
            cout << "Empty Stack!" << endl;
        } else {
            temp = top->data;
            temp_node = top;
            top = top->next;
            delete temp_node;
            temp_node = NULL;
            size--;
        }
        return temp;
    }
};

#endif