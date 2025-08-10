#include <stdio.h>
#include <stdlib.h>

#define SIZE 5  // Change the size as needed

int queue[SIZE];
int front = -1, rear = -1;

// Enqueue operation
void enqueue(int value) {
    if ((front == 0 && rear == SIZE - 1) || (rear + 1) % SIZE == front) {
        printf("Queue Overflow. Cannot insert %d\n", value);
        return;
    }

    if (front == -1) {
        front = rear = 0;
    } else {
        rear =
