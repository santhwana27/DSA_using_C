#include <stdio.h>

#define SIZE 5

int cq[SIZE];
int front = -1, rear = -1;

void enqueue(int val) {
    if ((rear + 1) % SIZE == front) {
        printf("Queue Full\n");
    } else {
        if (front == -1)
            front = rear = 0;
        else
            rear = (rear + 1) % SIZE;

        cq[rear] = val;
        printf("%d inserted\n", val);
    }
}

void dequeue() {
    if (front == -1) {
        printf("Queue Empty\n");
    } else {
        printf("Deleted: %d\n", cq[front]);

        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % SIZE;
    }
}

void display() {
    if (front == -1) {
        printf("Queue Empty\n");
    } else {
        int i = front;

        while (i != rear) {
            printf("%d ", cq[i]);
            i = (i + 1) % SIZE;
        }

        printf("%d\n", cq[rear]);
    }
}

int main() {
    int ch, val;

    while (1) {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                enqueue(val);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid Choice\n");
        }
    }
}
