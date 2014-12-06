//
//  queue.h
//  This is the header file of sathish's queue implementation.
//  Created by Sathish H Bowatta on 12/6/14.
//  Copyright (c) 2014 Sathish H Bowatta. All rights reserved.
//

typedef struct queueNode{
    int data;
    struct queueNode *next;
}Node;

typedef struct {
    Node *head, *tail;
}Queue;

bool isEmpty(Queue *q){
    if (q->head == NULL && q->tail == NULL)
        return true;
    else
        return false;
}

Node *newQueueNode(int data){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    return newNode;
}

Queue *initQueue(){
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->head = NULL;
    q->tail = NULL;
    return q;
}

void enqueue(Queue *q, int data){
    Node *newNode = newQueueNode(data);
    if (q->head == NULL && q->tail == NULL){
        q->head = newNode;
        q->tail = newNode;
    }
    else{
        q->tail->next = newNode;
        q->tail = newNode;
    }
}

int dequeue(Queue *q){
    if (isEmpty(q)){
        fprintf(stderr, "Error : Queue is Empty\n");
        exit(1);
    }
    int value;
    value = q->head->data;
    Node *temp = q->head;
    q->head = q->head->next;
    if (q->head == NULL)
        q->tail = NULL;
    free(temp);
    return value;
}

int peek(Queue *q){
    if (isEmpty(q)){
        fprintf(stderr, "Error : Queue is Empty\n");
        exit(1);
    }
    int value;
    value = q->head->data;
    return value;
}
