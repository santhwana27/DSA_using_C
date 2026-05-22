#include <stdio.h>

#define SIZE 5

int dq[SIZE], front = -1, rear = -1;

void insertFront(int x) {
    if ((rear + 1) % SIZE == front) {
        printf("Deque Full\n");
        return;
    }

    if (front == -1)
        front = rear = 0;
    else
        front = (front - 1 + SIZE) % SIZE;

    dq[front] = x;
}

void insertRear(int x) {
    if ((rear + 1) % SIZE == front) {
        printf("Deque Full\n");
        return;
    }

    if (front == -1)
        front = rear = 0;
    else
        rear = (rear + 1) % SIZE;

    dq[rear] = x;
}

void deleteFront() {
    if (front == -1) {
        printf("Deque Empty\n");
        return;
    }

    printf("Deleted: %d\n", dq[front]);

    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % SIZE;
}

void deleteRear() {
    if (front == -1) {
        printf("Deque Empty\n");
        return;
    }

    printf("Deleted: %d\n", dq[rear]);

    if (front == rear)
        front = rear = -1;
    else
        rear = (rear - 1 + SIZE) % SIZE;
}

void display() {
    if (front == -1) {
        printf("Deque Empty\n");
        return;
    }

    int i = front;

    while (1) {
        printf("%d ", dq[i]);

        if (i == rear)
            break;

        i = (i + 1) % SIZE;
    }

    printf("\n");
}

int main() {
    int ch, x;

    while (1) {
        printf("\n1.Insert Front\n2.Insert Rear\n3.Delete Front\n4.Delete Rear\n5.Display\n6.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &x);
                insertFront(x);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &x);
                insertRear(x);
                break;

            case 3:
                deleteFront();
                break;

            case 4:
                deleteRear();
                break;

            case 5:
                display();
                break;

            case 6:
                return 0;

            default:
                printf("Invalid Choice\n");
        }
    }
}
