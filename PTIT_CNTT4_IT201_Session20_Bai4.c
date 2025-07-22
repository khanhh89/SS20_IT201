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

void inorderTraversal(Node *root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int countLeaves(Node *root) {
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return countLeaves(root->left) + countLeaves(root->right);
}

int main() {
     Node *root = createNode(0);
    root->left = createNode(1);
    root->right = createNode(2);
    root->left->left = createNode(3);
    root->left->right = createNode(4);
    inorderTraversal(root);
    printf("\n");
    printf("So la trngo cay lla: %d\n", countLeaves(root));
    return 0;
}