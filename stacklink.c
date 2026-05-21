#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;

// Push operation
void push(int val) {

    struct node *newnode;

    newnode = (struct node*)malloc(sizeof(struct node));

    newnode->data = val;
    newnode->next = top;
    top = newnode;

    printf("%d pushed\n", val);
}

// Pop operation
void pop() {

    struct node *temp;

    if (top == NULL) {
        printf("Stack Empty\n");
    }

    else {
        temp = top;

        printf("Deleted: %d\n", top->data);

        top = top->next;

        free(temp);
    }
}

// Display operation
void display() {

    struct node *temp;

    if (top == NULL) {
        printf("Stack Empty\n");
    }

    else {

        temp = top;

        while (temp != NULL) {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
    }
}

int main() {

    int ch, val;

    while (1) {

        printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
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
                display();
                break;

            case 4:
                return 0;
        }
    }
}
