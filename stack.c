#include <stdio.h>

#define SIZE 10

int stack[SIZE];
int top = -1;

void push(int val) {
    if (top == SIZE - 1) {
        printf("Stack Full\n");
    } else {
        stack[++top] = val;
        printf("%d pushed\n", val);
    }
}

void pop() {
    if (top == -1) {
        printf("Stack Empty\n");
    } else {
        printf("Popped: %d\n", stack[top--]);
    }
}

void peek() {
    if (top == -1) {
        printf("Stack Empty\n");
    } else {
        printf("Top Element: %d\n", stack[top]);
    }
}

void display() {
    if (top == -1) {
        printf("Stack Empty\n");
    } else {
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

int main() {
    int ch, val;

    while (1) {
        printf("\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                push(val);
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                return 0;

            default:
                printf("Invalid Choice\n");
        }
    }
}
