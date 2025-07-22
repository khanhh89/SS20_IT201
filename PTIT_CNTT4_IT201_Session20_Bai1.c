//
// Created by khanh on 7/22/2025.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
}Node;

Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
}

int main() {
    printf("Nhap so nguyen: ");
    int n;
    scanf("%d", &n);
    Node *root = createNode(n);
     printf("node = {\n");
    printf("   data: %d,\n", root->data);
    if (root->left == NULL) {
        printf("   left->NULL,\n");
    } else {
        printf("   left->not NULL,\n");
    }
    if (root->right == NULL) {
        printf("   right->NULL\n");
    } else {
        printf("   right->not NULL\n");
    }
    printf("}\n");
    return 0;
}