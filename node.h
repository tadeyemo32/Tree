// node.h
#ifndef NODE_H
#define NODE_H

#include <stdbool.h>

typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
    bool visited;
} Node;

Node* createNode(int value);
Node* insertNode(Node* root, int value);
void printTree(Node* root, int space);
void freeTree(Node* root);

#endif
