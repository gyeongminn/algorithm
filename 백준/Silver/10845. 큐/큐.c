#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 10000

typedef int element;
typedef struct Queue {
    element data[MAX_QUEUE_SIZE];
    int front;
    int rear;
    int size;
} CircularQueue;

void initQueue(CircularQueue* q) {
    q->size = 0;
    q->front = 0;
    q->rear = 0;
}

int isEmpty(CircularQueue* q) {
    return q->front == q->rear;
}

int isFull(CircularQueue* q) {
    return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}

int size(CircularQueue* q) {
    return q->size;
}

element front(CircularQueue* q) {
    if (isEmpty(q))
        return -1;
    return q->data[q->front + 1];
}

element back(CircularQueue* q) {
    if (isEmpty(q))
        return -1;
    return q->data[q->rear];
}

void enqueue(CircularQueue* q, element value) {
    if (isFull(q))
        return;
    q->size++;
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = value;
}

element dequeue(CircularQueue* q) {
    if (isEmpty(q))
        return -1;
    q->size--;
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

int main(void) {
    int n;
    char opt[6];
    element data;
    CircularQueue* q = (CircularQueue*)malloc(sizeof(CircularQueue));
    initQueue(q);
    scanf("%d", &n);
    while (n--) {
        scanf("%s", opt);
        if (strcmp(opt, "push") == 0) {
            scanf("%d", &data);
            enqueue(q, data);
        } else if (strcmp(opt, "pop") == 0) {
            printf("%d\n", dequeue(q));

        } else if (strcmp(opt, "size") == 0) {
            printf("%d\n", size(q));

        } else if (strcmp(opt, "empty") == 0) {
            printf("%d\n", isEmpty(q));

        } else if (strcmp(opt, "front") == 0) {
            printf("%d\n", front(q));

        } else if (strcmp(opt, "back") == 0) {
            printf("%d\n", back(q));
        }
    }
    free(q);
}