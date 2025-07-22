//
// Created by khanh on 7/22/2025.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node *createNote(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void addNode(Node *root, int value) {
    if (root == NULL) {
        return;
    }
    Node *queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    Node *lastNode = NULL;
    while (front < rear) {
        Node *current = queue[front++];
        lastNode = current;

        if (current->left != NULL) {
            queue[rear++] = current->left;
        }
        if (current->right != NULL) {
            queue[rear++] = current->right;
        }
    }

    if (lastNode->right == NULL) {
        lastNode->right = createNode(value);
    } else {
        lastNode->left = createNode(value);
    }
}

void inorderTraversal(Node *root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    Node *root = createNode(0);
    root->left = createNode(1);
    root->right = createNode(2);
    root->left->left = createNode(3);
    root->left->right = createNode(4);
    inorderTraversal(root);
    printf("\n");
    addNode(root, 6);
    inorderTraversal(root);
    printf("\n");
    return 0;
}

