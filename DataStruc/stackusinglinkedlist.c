#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} stack;

stack *makenode()
{
    stack *p = (stack *)malloc(sizeof(stack));
    p->next = 0;
    printf("Enter data: ");
    scanf("%d", &p->data);
    return p;
}

stack *push(stack *h)
{
    if (h == 0)
    {
        stack *p = makenode();
        return p;
    }
    stack *p = makenode();
    p->next = h;
    return p;
}

stack *pop(stack *h)
{
    if (h == 0)
    {
        printf("Stack underflow!\n");
        return 0;
    }
    stack *p = h;
    h = h->next;
    printf("Popped %d", p->data);
    free(p);
    return h;
}
int main()
{
    int ch;
    stack *head = 0;
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
            head = push(head);
            break;
        case 2:
            head = pop(head);
            break;
        default:
            printf("Thanks a lot!");
            exit(0);
        }
    }
    return 0;
}