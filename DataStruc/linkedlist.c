#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} LL;

// Create a node
LL *makenode()
{
    LL *p;
    p = (LL *)malloc(sizeof(LL));
    printf("Enter data: ");
    scanf("%d", &p->data);
    p->next = 0;
    return p;
}

// Add first node
LL *addfirst(LL *head)
{
    LL *p;
    p = makenode();
    p->next = head;
    return p; // p is the head now
}

// Add last node
LL *addlast(LL *head)
{
    LL *p, *t;
    p = makenode();
    // When the list is empty
    if (head == 0)
    {
        // Here the head changes
        return p;
    }
    t = head;
    // When the list is not empty
    while (t->next != 0)
    {
        t = t->next;
    }
    t->next = p;
    // Here the head remains the same
    return head;
}

// Delete First
LL *delFirst(LL *head)
{
    // Element is there or no element
    if (head == 0)
    {
        printf("List is already empty\n");
        return head;
    }
    LL *t = head;
    head = head->next;
    printf("Deleting %d\n", t->data);
    free(t);
    return head;
}

// Delete last
LL *dellast(LL *h)
{
    LL *t, *p;
    if (h == 0)
    {
        printf("List is empty");
        return 0;
    }
    if (h->next == 0)
    {
        printf("Deleting %d", h->data);
        free(h);
        return 0;
    }
    t = h;
    while (t->next->next != 0)
    {
        t = t->next;
    }
    p = t->next;
    t->next = 0;
    printf("Deleting %d", p->data);
    free(p);
    return h;
}

// Add between
LL *addpos(LL *h)
{
    int count = 0, pos;
    if (h)
        count = 1;
    LL *t = h;
    if (h)
    {
        while (t->next != 0)
        {
            t = t->next;
            count++;
        }
    }
    printf("We have %d nodes in the list ..Please enter the position where you want to add the node", count);
    scanf("%d", &pos);
    // we can not insert the new node at the 0th pos only at 1st place and also only one more than the count like if count is 5then we
    // can have position as 6th but not 7th or more
    if (pos < 1 || pos > count + 1)
    {
        printf("mission impossible");
        return h;
    }
    if (pos == 1)
    {
        h = addfirst(h);
        return h;
    }
    if (pos == count + 1)
    {
        h = addlast(h);
        return h;
    }
    t = h;
    for (int i = 2; i < pos; i++)
    {
        t = t->next;
    }
    LL *p = makenode();
    p->next = t->next;
    t->next = p;
    return h;
}
// Delete between
LL *delpos(LL *h)
{
    int count = 0, pos;
    if (h)
        count = 1;
    LL *t = h;
    while (t->next != 0)
    {
        t = t->next;
        count++;
    }
    printf("We have %d nodes in the list ..Please enter the position where you want to delete the node", count);
    scanf("%d", &pos);
    if (pos < 1 || pos > count)
    {
        printf("mission impossible");
        return h;
    }
    if (pos == 1)
    {
        h = delFirst(h);
        return h;
    }
    if (pos == count)
    {
        h = dellast(h);
        return h;
    }
    t = h;
    for (int i = 2; i < pos; i++)
    {
        t = t->next;
    }
    LL *p;
    p = t->next;
    t->next = p->next;
    printf("Deleting %d", p->data);
    free(p);
    return h;
}
// Display the list
void display(LL *head)
{
    if (head == 0)
    {
        printf("List is empty\n");
        return;
    }
    LL *t = head;
    printf("List elements: ");
    while (t != 0)
    {
        printf("%d ", t->data);
        t = t->next;
    }
}

int main()
{
    LL *head = 0;
    int choice;

    do
    {
        printf("\nMenu:\n");
        printf("1. Add First\n");
        printf("2. Add Last\n");
        printf("3. Delete First\n");
        printf("4. Delete Last\n");
        printf("5. Add between\n");
        printf("6. Delete between\n");
        printf("7. Display List\n");
        printf("8. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            head = addfirst(head);
            break;
        case 2:
            head = addlast(head);
            break;
        case 3:
            head = delFirst(head);
            break;
        case 4:
            head = dellast(head);
            break;
        case 5:
            head = addpos(head);
            break;
        case 6:
            head = delpos(head);
            break;
        case 7:
            display(head);
            break;
        case 8:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 8);

    return 0;
}
