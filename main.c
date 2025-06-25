// main.c
#include <stdio.h>
#include "node.h"
#include "queue.h"

void bfs(Node* root) {
    if (root == NULL) return;

    Queue q;
    initQueue(&q);
    enQueue(&q, root);

    printf("\nBFS Traversal:\n");

    while (!isQueueEmpty(&q)) {
        Node* current = deQueue(&q);
        printf("%d ", current->value);

        if (current->left)
            enQueue(&q, current->left);
        if (current->right)
            enQueue(&q, current->right);
    }

    printf("\n");
}

int main() {
    Node* root = NULL;

    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 70);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 60);
    root = insertNode(root, 80);

    printTree(root, 0);
    bfs(root);
    freeTree(root);
    return 0;
}
