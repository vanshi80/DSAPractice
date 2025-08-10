#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

// Push function
void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed. Stack Overflow.\n");
        return;
    }
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

// Pop function
void pop() {
    if (top == NULL) {
        printf("Stack Underflow. Nothing to pop.\n");
        return;
    }
    struct Node* temp = top;
    printf("Popped %d \n", top->data);
    top = top->next;
    free(temp);
}

// Main function with menu
int main() {
    int choice, value;

    while (1) {
        printf("\nMenu \n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value: ");
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
