#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "raylib.h"

#define NODE_RADIUS 20
#define V_SPACING 80
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define BUTTON_WIDTH 100
#define BUTTON_HEIGHT 40
#define BUTTON_SPACING 20




typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;




Node* createNode(int data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->value = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node *root, int data) {
    if (root == NULL) return createNode(data);

    if (data < root->value)
        root->left = insertNode(root->left, data);
    else if (data > root->value)
        root->right = insertNode(root->right, data);

    return root;
}
void printTree(Node* root, int space) {
    if (root == NULL)
        return;

    int indent = 5;

    // Print right child first (top of tree)
    printTree(root->right, space + indent);

    // Print current node
    for (int i = 0; i < space; i++)
        printf(" ");
    printf("%d\n", root->value);

    // Then print left child
    printTree(root->left, space + indent);
}








int main(void) {
    Node* root = NULL;
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 70);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 60);
    root = insertNode(root, 80);
printTree(root,0);

}
