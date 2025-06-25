// queue.h
#ifndef QUEUE_H
#define QUEUE_H

#include "node.h"

#define MaxNodes 100

typedef struct Queue {
    Node* nodes[MaxNodes];
    int front;
    int rear;
} Queue;

void initQueue(Queue* queue);
void enQueue(Queue* queue, Node* node);
Node* deQueue(Queue* queue);
int isQueueEmpty(Queue* queue);

#endif
