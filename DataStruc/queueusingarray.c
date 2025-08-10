#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

// Enqueue operation
void enqueue(int value) {
    if (rear == SIZE - 1) {
        printf("Queue Overflow");
        return;
    }
    if (front == -1)
        front = 0;
    rear++;
    queue[rear] = value;
}

// Dequeue operation
void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow.\n");
        return;
    }
    printf("Deleting... %d \n", queue[front]);
    front++;
}

// Main function with menu
int main() {
    int choice, value;

    while (1) {
        printf("\nMenu\n");
        printf("1. Insert in queue\n");
        printf("2. Delete from queue\n");
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
