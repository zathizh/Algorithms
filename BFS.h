//
//  bfs.h
//  This is the header file of sathish's BFS implementation.
//  Created by Sathish H Bowatta on 12/8/14.
//  Copyright (c) 2014 Sathish H Bowatta. All rights reserved.
//

#define WHITE -1
#define GRAY 0
#define BLACK 1

void INITIALISE_SINGLE(int distance[], int predecessor[], int colour[], int size, int source){
    int v = size;
    for(v = 0; v < size; v++){
        colour[v] = WHITE;
        distance[v]= INT_MAX;
        predecessor[v] = -1;
    }
    colour[source] = GRAY;
    distance[source] = 0;
}

void BFS(Graph *graph, int source){
    int size = graph->size;
    int distance[size];
    int predecessor [size];
    int colour [size];
    
    INITIALISE_SINGLE(distance, predecessor, colour, size, source);
    
    Queue *Q = initQueue();
    enqueueToQueue(Q, source);
    
    while (isQueueEmpty(Q)) {
        int u = dequeueToQueue(Q);
        
        AdjListNode* pCrawl = graph->array[u].head;
        
        while (pCrawl != NULL){
            int v = pCrawl->dest;
            if (colour[v] == WHITE){
                colour[v] = GRAY;
                distance[v] = distance[u] +1;
                predecessor[v] = u;
                
                enqueueToQueue(Q, v);
            }
            pCrawl = pCrawl->next;
        }
        colour[u] = BLACK;
    }
}
