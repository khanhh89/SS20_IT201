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
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int findfloor(Node *root, int key, int floor) {
    if (root == NULL)
        return 0;
    if (root->data == key)
        return floor;
    int downfloor = findfloor(root->left, key, floor + 1);
    if (downfloor != 0)
        return downfloor;
    return findfloor(root->right, key, floor + 1);
}

int main() {
    Node *root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(30);
    root->left->left = createNode(2);
    root->left->right = createNode(8);
    root->right->left = createNode(25);
    root->right->right = createNode(35);
    int key = 25;
    int level = findfloor(root, key, 1);
    if (level != 0)
        printf("Node %d o tang %d\n", key, level);
    else
        printf("Khong tim thay node %d trong cay\n", key);
    return 0;
}
