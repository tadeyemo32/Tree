// queue.c
#include <stdio.h>
#include "queue.h"

void initQueue(Queue* queue) {
    queue->front = 0;
    queue->rear = -1;
}

void enQueue(Queue* queue, Node* node) {
    if (queue->rear == MaxNodes - 1) {
        printf("Queue overflow!\n");
        return;
    }
    queue->nodes[++queue->rear] = node;
}

Node* deQueue(Queue* queue) {
    if (queue->front > queue->rear) {
        printf("Queue is empty!\n");
        return NULL;
    }
    Node* node = queue->nodes[queue->front++];
    return node;
}

int isQueueEmpty(Queue* queue) {
    return queue->front > queue->rear;
}
