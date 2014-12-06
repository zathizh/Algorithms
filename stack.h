//
//  stack.h
//  This is the header file of sathish's stack implementation.
//  Created by Sathish H Bowatta on 12/6/14.
//  Copyright (c) 2014 Sathish H Bowatta. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct stackNode{
    int data;
    struct stackNode *next;
}Node;

typedef struct {
    Node *top;
} Stack;

Stack *initStack(){
    Stack *sp = (Stack *)malloc(sizeof(Stack));
    sp->top = NULL;
    return sp;
}

bool isEmpty(Stack *S){
    if (S->top == NULL)
        return true;
    else
        return false;
}

Node *newStackNode (int data){
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) {
        puts("Memory Allocation Failure");
        EXIT_FAILURE;
    }
    
    newNode->data = data;
    return newNode;
}

void push(Stack *Stk, int data){
    Node *np = newStackNode(data);
    np->data = data;
    np->next = Stk->top;
    Stk->top = np;
}

int pop(Stack *Stk){
    if (isEmpty(Stk)){
        puts("Stack is Empty");
    }
    else{
        int value  = Stk->top->data;
        Node *temp = Stk->top;
        Stk->top = Stk->top->next;
        free(temp);
        return value;
    }
}

int peek(Stack *Stk){
    if (isEmpty(stk)){
        puts("Stack is Empty")
    }
    else {
        int value = Stk->top->data;
        return value;
    }
}

void delete (Stack *Stk){
    Node *temp = Stk->top;
    Stk->top = Stk->top->next;
    free(temp);
}
