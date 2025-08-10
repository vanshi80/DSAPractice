#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

// Enqueue operation (insert at rear)
void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed. Queue Overflow.\n");
        return;
    }
    newNode->data = value;

    if (front == NULL) {
        front = rear = newNode;
        rear->next = front;
    } else {
        rear->next = newNode;
        rear = newNode;
        rear->next = front; // Make it circular
    }
}

// Dequeue operation (remove from front)
void dequeue() {
    if (front == NULL) {
        printf("Queue is already empty.\n");
        return;
    }

    struct Node* temp = front;
    if (front == rear) {
        printf("Deleting... %d\n", front->data);
        front = rear = NULL;
    } else {
        printf("Deleting... %d\n", front->data);
        front = front->next;
        rear->next = front;  // Maintain circular link
    }
    free(temp);
}
// Main function with menu
int main() {
    int choice, value;

    while (1) {
        printf("\nMenu\n");
        printf("1. Insert in circular queue\n");
        printf("2. Delete from circular queue\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            default:
                printf("Thanks a lot!\n");
                exit(0);
        }
    }

    return 0;
}
