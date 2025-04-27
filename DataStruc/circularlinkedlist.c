#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} CL;

// make node function
CL *makenode()
{
    CL *p = (CL *)malloc(sizeof(CL));
    p->next = 0;
    printf("Enter data: ");
    scanf("%d", &p->data);
    return p;
}

// Add first node
CL *addfirst(CL *h)
{
    CL *p = makenode();
    if (h == 0)
    {
        p->next = p;
        return p;
    }
    CL *t = h;
    while (t->next != h)
    {
        t = t->next;
    }
    t->next = p;
    p->next = h;
    return p;
}
// Delete first node
CL *delfirst(CL *h)
{
    CL *p, *t;
    if (h == 0)
    {
        printf("List is empty!\n");
        return 0;
    }
    if (h->next == h)
    {
        printf("Deleting %d", h->data);
        free(h);
        return 0;
    }
    t = h;
    while (t->next != h)
    {
        t = t->next;
    }
    p = h;
    h = h->next;
    t->next = h;
    printf("Deleting %d", p->data);
    free(p);
    return h;
}
// Add last node
CL *addlast(CL *h)
{
    CL *p = makenode();
    if (h == 0)
    {
        p->next = p;
        return p;
    }
    if (h->next == h)
    {
        h->next = p;
        p->next = h;
        return h;
    }
    CL *t = h;
    while (t->next != h)
    {
        t = t->next;
    }
    t->next = p;
    p->next = h;
    return h;
}
// Delete last node
CL *dellast(CL *h)
{
    CL *p;
    if (h == 0)
    {
        printf("List is already empty!\n");
        return h;
    }
    if (h->next == h)
    {
        printf("Deleting %d\n", h->data);
        free(h);
        return 0;
    }
    CL *t = h;
    while (t->next->next != h)
    {
        t = t->next;
    }
    p = t->next;
    t->next = h;
    printf("Deleting %d", p->data);
    free(p);
    return h;
}
// Add at a position
CL *addpos(CL *h)
{
    CL *t, *p;
    int pos, count = 0;
    if (h)
        count = 1;
    t = h;
    while (t->next != h)
    {
        t = t->next;
        count++;
    }
    printf("We have %d nodes. Enter the position where you wish to add new node", count);
    scanf("%d", &pos);
    if (pos < 1 || pos > count + 1)
    {
        printf("Mission Impossible!");
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
    p = makenode();
    t = h;
    for (int i = 2; i < pos; i++)
    {
        t = t->next;
    }
    p->next = t->next;
    t->next = p;
    return h;
}
// Delete from position
CL *delpos(CL *h)
{
    int count = 0, pos;
    if (h)
        count = 1;
    CL *t = h;
    while (t->next != h)
    {
        t = t->next;
        count++;
    }
    printf("We have %d nodes in the list.Please enter the position where you want to delete the node: ", count);
    scanf("%d", &pos);
    if (pos < 1 || pos > count)
    {
        printf("Mission impossible!\n");
        return h;
    }
    if (pos == 1)
    {
        h = delfirst(h);
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
    CL *p;
    p = t->next;
    t->next = p->next;
    printf("Deleting %d", p->data);
    free(p);
    return h;
}
// Display function
void display(CL *h)
{
    CL *t = h;
    do
    {
        printf("%d ", t->data);
        t = t->next;
    } while (t != h);
}
int main()
{
    CL *h = 0;
    int choice;
    while (1)
    {
        printf("\nMenu\n");
        printf("1.Add first\n");
        printf("2.Delete first\n");
        printf("3.Add last\n");
        printf("4.Delete last\n");
        printf("5.Add at a position\n");
        printf("6.Delete from a position\n");
        printf("7.Display list\n");
        printf("8.Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            h = addfirst(h);
            break;
        case 2:
            h = delfirst(h);
            break;
        case 3:
            h = addlast(h);
            break;
        case 4:
            h = dellast(h);
            break;
        case 5:
            h = addpos(h);
            break;
        case 6:
            h = delpos(h);
            break;
        case 7:
            display(h);
            break;
        default:
            printf("Thanks a lot!\n");
            exit(0);
        }
    }
    return 0;
}