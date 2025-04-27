#include <stdlib.h>
#include <stdio.h>
#define size 5
int top = -1;
int stack[size];
void push()
{
    if (top == size - 1)
    {
        printf("Stack overflow!\n");
        return;
    }
    top++;
    printf("Enter data: ");
    scanf("%d", &stack[top]);
}
void pop()
{
    if (top == -1)
    {
        printf("Stack underflow!\n");
        return;
    }
    printf("Popped %d", stack[top]);
    top--;
}
int main()
{
    int ch;
    while (1)
    {
        // system("cls");
        printf("\nMenu\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Exit\n");
        printf("Enter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        default:
            printf("Thanks a lot!");
            exit(0);
        }
    }
    return 0;
}