#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *prev, *next;
} CDL;

// Making a node
CDL *makenode()
{
    CDL *p = (CDL *)malloc(sizeof(CDL));
    printf("Enter data: ");
    scanf("%d", &p->data);
    p->next = 0;
    p->prev = 0;
    return p;
}

// Add first node
CDL *addfirst(CDL *h)
{
    CDL *p = makenode();
    if (h == 0)
    {
        p->prev = p->next = p;
        return p;
    }
    // if (h->next == h)
    // {
    //     h->next = p;
    //     p->next = p;
    //     return p;
    // }
    h->prev->next = p;
    p->prev = h->prev;
    p->next = h;
    h->prev = p;
    return p;
}
// Delete First node
CDL *delfirst(CDL *h)
{
    CDL *t;
    if (h == 0)
    {
        printf("List is empty!\n");
        return 0;
    }
    // if (h->next == h)
    // {
    //     printf("Deleting %d", h->data);
    //     free(h);
    //     return 0;
    // }
    t = h;
    h->prev->next = h->next;
    h->next->prev = h->prev;
    h = h->next;
    printf("Deleting %d", t->data);
    free(t);
    return h;
}
// Add last function
CDL *addlast(CDL *h)
{
    CDL *p = makenode();
    if (h == 0)
    {
        p->next = p->prev = p;
        return p;
    }
    if (h->next == h)
    {
        h->next = p;
        p->next = h;
        p->prev = h;
        h->prev = p;
        return h;
    }
    // when we have more than one node available
    h->prev->next = p;
    p->prev = h->prev;
    h->prev = p;
    p->next = h;
    return h;
}
// Delet last node
CDL *dellast(CDL *h)
{
    if (h == 0)
    {
        printf("List is already empty!");
        return 0;
    }
    if (h->next == h)
    {
        printf("Deleting %d", h->data);
        free(h);
        return 0;
    }
    CDL *p;
    p = h->prev;
    p->prev->next = h;
    h->prev = p->prev;
    printf("Deleting %d", p->data);
    free(p);
    return h;
}
// Add at a position
CDL *addpos(CDL *h)
{
    CDL *t, *p;
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
CDL *delpos(CDL *h)
{
    int count = 0, pos;
    if (h)
        count = 1;
    CDL *t = h;
    while (t->next != h)
    {
        t = t->next;
        count++;
    }
    printf("We have %d nodes in the list ..Please enter the position where you want to delete the node", count);
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
    CDL *p;
    p = t->next;
    t->next = p->next;
    printf("Deleting %d", p->data);
    free(p);
    return h;
}
// Display function
void display(CDL *h)
{
    if (h == 0)
    {
        printf("List is empty!\n");
        return;
    }
    else
    {
        CDL *t = h;
        do
        {
            printf("%d ", t->data);
            t = t->next;
        } while (t != h);
    }
}
int main()
{
    CDL *h = 0;
    int ch;
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

        printf("Enter your choice");
        scanf("%d", &ch);

        switch (ch)
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