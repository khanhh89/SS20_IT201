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

int findMax(Node *root) {
    if (root == NULL) {
        return -999;
    }
    int maxLeft = findMax(root->left);
    int maxRight = findMax(root->right);
    int maxChild;
    if (maxLeft > maxRight) {
        maxChild = maxLeft;
    } else {
        maxChild = maxRight;
    }
    int maxValue;
    if (root->data > maxChild) {
        maxValue = root->data;
    } else {
        maxValue = maxChild;
    }
    return maxValue;
}

void inorderTraversal(Node *root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    Node *root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(30);
    root->left->left = createNode(2);
    root->left->right = createNode(8);
    root->right->left = createNode(25);
    root->right->right = createNode(35);
    inorderTraversal(root);
    printf("\n");
    printf("Gia tri lon nhat trong cay: %d\n", findMax(root));
    return 0;
}
