//
//  LinkedList.h
//  This is the header file of sathish's Linked List implementation.
//  Created by Sathish H Bowatta on 12/7/14.
//  Copyright (c) 2014 Sathish H Bowatta. All rights reserved.
//

typedef struct linkedListnode{
    int data;
    struct linkedListnode *next, *prev;
}LinkedListNode;

typedef struct {
    LinkedListNode *head, *tail;
}LinkedList;

LinkedListNode *newLinkedListNode(int data){
    LinkedListNode *newNode = (LinkedListNode *)malloc(sizeof(LinkedListNode));
    if (!newNode) {
        fprintf(stderr, "Error : Memory Allocating\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

LinkedList *initLinkedLst(){
    LinkedList *lnkdlst = (LinkedList *)malloc(sizeof(LinkedList));
    lnkdlst->head = NULL;
    lnkdlst->tail = NULL;
    return lnkdlst;
}

void pushToLinkedList(LinkedList *lnkdlst, int data){
    LinkedListNode *newNode = newLinkedListNode(data);
    if (lnkdlst->head == NULL && lnkdlst->tail == NULL) {
        lnkdlst->head = newNode;
        lnkdlst->tail = newNode;
    }
    
    newNode->prev = lnkdlst->tail;
    lnkdlst->tail->next = newNode;
    lnkdlst->tail = newNode;
}

int lengthOfLinkedList(LinkedList *lnkdlst){
    
    LinkedListNode *temp = lnkdlst->head;
    if(temp == NULL){
        fprintf(stderr, "Error : Linked List is empty\n");
        exit(1);
    }
    int len = 0;
    while (temp != NULL) {
        temp = temp->next;
        len++;
    }
    return len;
}

int searchInLinkedList(LinkedList *lnkdlst, int searchValue){
    int index =0;
    LinkedListNode *temp = lnkdlst->head;
    
    while (temp != NULL) {
        
        if (temp->data == searchValue)
            return index;
        
        temp = temp->next;
        index++;
    }
    return -1;
}

void deleteFromLinkedList(LinkedList *lnkdlst, int value){
    int index = searchInLinkedList(lnkdlst, value);
    if (index != -1){
        LinkedListNode *temp = lnkdlst->head;
        if (index == 0){
            temp->next = NULL;
            temp->prev = NULL;
        }
        else {
            int i;
            for(i = 0; i < index ; i++ ){
                temp = temp->next;
            }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }    
        free(temp);
    }
}

void deleteIndexFromLinkedList(LinkedList *lnkdlst, int index){
    
    LinkedListNode *temp = lnkdlst->head;
    int i;
    for(i = 0; i < index ; i++ ){
        temp = temp->next;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
}
