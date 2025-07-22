//
// Created by khanh on 7/22/2025.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    struct node *left;
    struct node *right;
    int data;
}node;

typedef struct Queue {
    int front;
    int rear;
    node **arr;
    int capacity;
} Queue;

Queue *createQueue(int capacity) {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = 0;
    queue->rear = -1;
    queue->capacity = capacity;
    queue->arr = (node **)malloc(capacity * sizeof(node *));
    return queue;
}

void enqueue(Queue *queue, node *data) {
    if (queue->rear == queue->capacity - 1) {
        printf("Queue is full\n");
        return;
    }
    queue->rear++;
    queue->arr[queue->rear] = data;
}

int isEmpty(Queue *queue) {
    return queue->front > queue->rear;
}

node *createNode(int data) {
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void preOrder(node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(node *root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

void postOrder(node *root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

void levelOrder(node *root) {
    if (root == NULL) return;
    Queue *queue = createQueue(100);
    enqueue(queue, root);

    while (!isEmpty(queue)) {
        node *current = queue->arr[queue->front++];
        printf("%d ", current->data);

        if (current->left != NULL)
            enqueue(queue, current->left);
        if (current->right != NULL)
            enqueue(queue, current->right);
    }
    free(queue->arr);
    free(queue);
}

int main() {
    node *root = NULL;
    root = createNode(1);
    node *node1 = createNode(2);
    node *node2 = createNode(3);
    node *node3 = createNode(4);
    node *node4 = createNode(5);
    node *node5 = createNode(6);

    root->left = node1;
    root->right = node2;
    node1->left = node3;
    node1->right = node4;
    node2->right = node5;
    node2->left = NULL;

    printf("Preorder:");
    preOrder(root);
    printf("\n");
    printf("Inorder:");
    inOrder(root);
    printf("\n");
    printf("Postorder:");
    postOrder(root);
    printf("\n");
    printf("Level Order:");
    levelOrder(root);
    printf("\n");
    return 0;
}