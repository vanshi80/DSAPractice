#include <stdio.h>
#include <stdlib.h>

#define SIZE 5  // Change size as needed

int stack[SIZE];
int top = -1;

// Push operation
void push(int value) {
    if (top == SIZE - 1) {
        printf("Stack Overflow.", value);
    } else {
        stack[++top] = value;
    }
}

// Pop operation
void pop() {
    if (top == -1) {
        printf("Stack Underflow.\n");
    } else {
        printf("Popped %d \n", stack[top--]);
    }
}

// Main menu-driven function
int main() {
    int choice, value;

    while (1) {
        printf("\nMenu\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            default:
                printf("Thanks a lot!\n");
                exit(0);
        }
    }

    return 0;
}
