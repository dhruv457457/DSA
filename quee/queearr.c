#include <stdio.h>
#include <stdlib.h>

#define Max 10

struct queue {
    int front;
    int rear;
    int queue[Max];
};
typedef struct queue qt;

void createQueue(qt *pq) {
    pq->front = -1;
    pq->rear = -1;
}

int isEmpty(qt *pq) {
    return (pq->front == -1 || pq->front > pq->rear);
}

int isFull(qt *pq) {
    return (pq->rear == Max - 1);
}

void enqueue(qt *pq, int val) {
    if (isFull(pq)) {
        printf("Queue is full\n");
        return;
    }
    if (pq->front == -1) {
        pq->front = 0;
    }
    pq->rear++;
    pq->queue[pq->rear] = val;
    printf("Enqueued: %d\n", val);
}

void dequeue(qt *pq) {
    if (isEmpty(pq)) {
        printf("Queue is empty\n");
        return;
    }
    int temp = pq->queue[pq->front];
    printf("Dequeued: %d\n", temp);
    pq->front++;
    if (pq->front > pq->rear) {  // Reset queue if it becomes empty
        pq->front = pq->rear = -1;
    }
}

void show(qt *pq) {
    if (isEmpty(pq)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements:\n");
    for (int i = pq->front; i <= pq->rear; i++) {
        printf("%d ", pq->queue[i]);
    }
    printf("\n");
}

int main() {
    qt q;
    createQueue(&q);

    int num, ch;
    do {
        printf("\nEnter your choice\n1. Enqueue\n2. Dequeue\n3. Show\n0. Exit\n");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter the number to enqueue: ");
                scanf("%d", &num);
                enqueue(&q, num);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                show(&q);
                break;
            case 0:
                exit(0);
            default:
                printf("Invalid input\n");
                break;
        }
    } while (1);

    return 0;
}
