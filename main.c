#include <stdio.h>
#include "node.h"
#include "queue.h"
#include "raylib.h"
#include <time.h>

void setPositions(Node* node, int x, int y, int spacing) {
    if (!node) return;
    node->x = x;
    node->y = y;
    setPositions(node->left, x - spacing, y + 80, spacing / 2);
    setPositions(node->right, x + spacing, y + 80, spacing / 2);
}

void drawTree(Node* node) {
    if (!node) return;

    if (node->left)
        DrawLine(node->x, node->y, node->left->x, node->left->y, DARKGRAY);
    if (node->right)
        DrawLine(node->x, node->y, node->right->x, node->right->y, DARKGRAY);

    drawTree(node->left);
    drawTree(node->right);

    Color color = node->visited ? GREEN : SKYBLUE;
    DrawCircle(node->x, node->y, 20, color);
    DrawText(TextFormat("%d", node->value), node->x - 10, node->y - 10, 20, BLACK);
}

void resetVisited(Node* root) {
    if (!root) return;
    root->visited = false;
    resetVisited(root->left);
    resetVisited(root->right);
}

Queue bfsQueue;
bool bfsRunning = false;
float bfsTimer = 0;

bool bfsStep(Node* root) {
    if (!isQueueEmpty(&bfsQueue)) {
        Node* current = deQueue(&bfsQueue);
        current->visited = true;
        if (current->left) enQueue(&bfsQueue, current->left);
        if (current->right) enQueue(&bfsQueue, current->right);
        return true;
    }
    return false;
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


    setPositions(root, 400, 60, 120);

    InitWindow(800, 600, "BFS Tree Visualizer");
    SetTargetFPS(60);

    Rectangle button = { 650, 500, 120, 40 };

    while (!WindowShouldClose()) {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) &&
            CheckCollisionPointRec(GetMousePosition(), button) &&
            !bfsRunning) {

            resetVisited(root);
            initQueue(&bfsQueue);
            enQueue(&bfsQueue, root);
            bfsRunning = true;
            bfsTimer = 0;
        }

        if (bfsRunning) {
            bfsTimer += GetFrameTime();
            if (bfsTimer >= 0.5f) {
                bfsRunning = bfsStep(root);
                bfsTimer = 0;
            }
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        drawTree(root);
        DrawRectangleRec(button, bfsRunning ? GRAY : LIGHTGRAY);
        DrawText("Start BFS", button.x + 10, button.y + 10, 20, DARKGRAY);
        EndDrawing();
    }

    CloseWindow();
    freeTree(root);
    return 0;
    
}
