// node.c
#include <stdio.h>
#include <stdlib.h>
#include "node.h"

Node* createNode(int value) {
    Node* newNode = malloc(sizeof(Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->visited = false;
    return newNode;
}

Node* insertNode(Node* root, int value) {
    if (root == NULL) return createNode(value);
    if (value < root->value)
        root->left = insertNode(root->left, value);
    else if (value > root->value)
        root->right = insertNode(root->right, value);
    return root;
}

void printTree(Node* root, int space) {
    if (root == NULL)
        return;

    int indent = 5;
    printTree(root->right, space + indent);

    for (int i = 0; i < space; i++)
        printf(" ");
    printf("%d\n", root->value);

    printTree(root->left, space + indent);
}

void freeTree(Node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}
