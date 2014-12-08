//
//  Graph.h
//  This is the header file of sathish's Linked List implementation.
//  Created by Sathish H Bowatta on 12/7/14.
//  Copyright (c) 2014 Sathish H Bowatta. All rights reserved.
//

typedef struct node{
    int dest;
    int weight;
    struct node *next;
    
}AdjListNode;

typedef struct {
    AdjListNode *head;
}AdjList;

typedef struct {
    int size;
    AdjList *array;
}Graph;

AdjListNode *newAdjListNode(int dest, int weight){
    AdjListNode *newNode = (AdjListNode *)malloc(sizeof(AdjListNode));
    if (!newNode) {
        fprintf(stderr, "Error : Memory Allocating\n");
        exit(1);
    }
    
    newNode->next = NULL;
    newNode->dest = dest;
    newNode->weight = weight;
    return newNode;
}

Graph *initGraph(int size){
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    if (!graph) {
        fprintf(stderr, "Error : Memory Allocating\n");
        exit(1);
    }
    
    graph->size = size;
    
    graph->array = (AdjList *)malloc(sizeof(AdjList) * size);
    if (!graph->array) {
        fprintf(stderr, "Error : Memory Allocating\n");
        exit(1);
    }
    
    int i;
    for (i = 0; i < size; ++i)
        graph->array[i].head = NULL;
    
    return graph;
}

void addEdge(Graph *graph, int src, int dest, int weight){
    AdjListNode *newNode = newAdjListNode(dest, weight);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
}


int outDegreeOfGraph(Graph *graph, int node){
    int odg=0;
    AdjListNode *temp = graph->array[node].head;
    
    do {
        odg++;
        temp = temp->next;
    } while (temp != NULL);
    
    return odg;
}

int inDegreeOfGraph(Graph *graph, int node){
    int indg = 0;
    int size = graph->size;
    int i;
    for (i = 0; i < size ; i++){
        AdjListNode *temp = graph->array[i].head;
        do{
            if (temp == NULL) {
                break;
            }
            else if (temp->dest == node) {
                indg++;
                break;
            }
            temp = temp->next;
        } while (temp != NULL);
        
        //free(temp);
    }
    return indg;
}
