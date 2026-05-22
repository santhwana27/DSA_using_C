#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insert(int x) {
    struct Node *n = malloc(sizeof(struct Node));
    n->data = x;
    n->next = head;
    head = n;
}

void delete(int x) {
    struct Node *t = head, *p = NULL;

    while (t && t->data != x) {
        p = t;
        t = t->next;
    }

    if (!t) return;

    if (!p)
        head = t->next;
    else
        p->next = t->next;

    free(t);
}

void display() {
    struct Node *t = head;

    while (t) {
        printf("%d -> ", t->data);
        t = t->next;
    }

    printf("NULL\n");
}

int main() {
    int ch, x;

    while (1) {
        printf("1.Insert 2.Delete 3.Display 4.Exit : ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                scanf("%d", &x);
                insert(x);
                break;

            case 2:
                scanf("%d", &x);
                delete(x);
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;
        }
    }
}
