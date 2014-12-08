//
//  stack.h
//  This is the header file of sathish's Stack implementation.
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

bool isStackEmpty(Stack *S){
    if (S->top == NULL)
        return true;
    else
        return false;
}

Node *newStackNode (int data){
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) {
        fprintf(stderr, "Error : Stack is Empty\n");
        exit(1);
    }
    newNode->data = data;
    return newNode;
}

void pushToStack(Stack *Stk, int data){
    Node *np = newStackNode(data);
    np->data = data;
    np->next = Stk->top;
    Stk->top = np;
}

int popFromStack(Stack *Stk){
    if (isStackEmpty(Stk)){
        fprintf(stderr, "Error : Stack is Empty\n");
        exit(1);
    }
    int value  = Stk->top->data;
    Node *temp = Stk->top;
    Stk->top = Stk->top->next;
    free(temp);
    return value;
}

int peekFromStack(Stack *Stk){
    if (isStackEmpty(stk)){
        fprintf(stderr, "Error : Stack is Empty\n");
        exit(1);
    }
    
    int value = Stk->top->data;
    return value;
}

void deleteFromStack(Stack *Stk){
    Node *temp = Stk->top;
    Stk->top = Stk->top->next;
    free(temp);
}
