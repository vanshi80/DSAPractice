#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int coeff, expo;
    struct node *next;
} poly;

void clear(poly *h)
{
    poly *t;
    if (h == 0)
        return;
    while (h)
    {
        t = h;
        h = h->next;
        free(t);
    }
}
// copy code
poly *copylist(poly *h)
{
    if (h == 0)
        return 0;
    poly *nhead = (poly *)malloc(sizeof(poly *));
    nhead->coeff = h->coeff;
    nhead->expo = h->expo;
    poly *p = h->next;
    poly *t = nhead;
    while (p != 0)
    {
        t->next = (poly *)malloc(sizeof(poly *));
        t->next->next = 0;
        t->next->coeff = p->coeff;
        t->next->expo = p->expo;
        t = t->next;
        p = p->next;
    }
    return nhead;
}
// copy negative
poly *copy_negative(poly *h)
{
    if (h == 0)
        return 0;
    poly *nhead = (poly *)malloc(sizeof(poly));
    nhead->coeff = (-1) * h->coeff;
    nhead->expo = h->expo;
    poly *p = h->next;
    poly *t = nhead;
    while (p != 0)
    {
        t->next = (poly *)malloc(sizeof(poly));
        t->next->next = 0;
        t->next->coeff = (-1) * p->coeff;
        t->next->expo = p->expo;
        t = t->next;
        p = p->next;
    }
    return nhead;
}
// Create a node
poly *makenode()
{
    poly *p;
    p = (poly *)malloc(sizeof(poly));
    printf("Enter Coefficient: ");
    scanf("%d", &p->coeff);
    printf("Enter Exponent: ");
    scanf("%d", &p->expo);
    p->next = 0;
    return p;
}

// Add first node
poly *addfirst(poly *head)
{
    poly *p;
    p = makenode();
    p->next = head;
    return p; // p is the head now
}

void display(poly *head)
{
    if (head == 0)
    {
        printf("Empty polynomial\n");
        return;
    }
    poly *t = head;
    printf("\nPolynomial: ");

    printf("%d x^%d ", t->coeff, t->expo);
    t = t->next;
    while (t != 0)
    {
        if (t->coeff >= 0)
            printf(" +%dx^%d", t->coeff, t->expo);
        else
            printf(" %dx^%d", t->coeff, t->expo); // minus is already in coeff
        t = t->next;
    }
}
poly *prune_and_sort(poly *h)
{
    poly *p = h, *t, *z, *prev;
    poly x;

    if (!h || h->next == 0)
    {
        return h;
    }
    while (p)
    {
        prev = p; // this prev changes with every t so that whenever equals case occurs then we could remove t connection after adding its coeff to p
        t = p->next;
        while (t)
        {
            // Sorting if lesser than the late value
            if (p->expo < t->expo)
            {
                x.coeff = p->coeff;
                x.expo = p->expo;

                p->coeff = t->coeff;
                p->expo = t->expo;

                t->coeff = x.coeff;
                t->expo = x.expo;
            }
            else if (p->expo == t->expo)
            { // pruning if we get equal exponents
                p->coeff += t->coeff;
                prev->next = t->next; // conncetion breaking
                z = t;
                t = t->next;
                free(z);
                z = 0;
                continue; // no need to update the prev and t bcz we have now different t already that we need to compare with p
            }
            prev = prev->next;
            t = t->next;
        }
        p = p->next;
    }
    return h;
}
void add(poly *h1, poly *h2)
{
    poly *h3, *t;
    if (h1 == 0 && h2 == 0)
        return;
    h3 = copylist(h1);
    if (h3)
    {
        // if there was h1 then only h3 ,so reach to its end and append h2 there
        t = h3;
        while (t->next != 0)
        {
            t = t->next;
        }
        if (h2)
            t->next = copylist(h2);
    }
    else
    {
        h3 = copylist(h2);
    }
    h3 = prune_and_sort(h3);
    printf("First polynomial : ");
    display(h1);
    printf("Second polynomial : ");
    display(h2);
    printf("Addition of polynomials: ");
    display(h3);
    clear(h3);
}
void subtract(poly *h1, poly *h2)
{
    poly *h3, *t;
    if (h1 == 0 && h2 == 0)
    {
        return;
    }
    h3 = copylist(h1);
    if (h3)
    {
        t = h3;
        while (t->next != 0)
        {
            t = t->next;
        }
        if (h2)
            t->next = copy_negative(h2);
    }
    else
    {
        h3 = copy_negative(h2);
    }
    h3 = prune_and_sort(h3);
    printf("First polynomial : ");
    display(h1);
    printf("Second polynomial : ");
    display(h2);
    printf("Subtraction of polynomials: ");
    display(h3);
    clear(h3);
}
void multiply(poly *h1, poly *h2)
{
    if (h1 == 0 && h2 == 0)
    {
        printf("Nothing to multiple\n");
        return;
    }
    if (h1 == 0 || h2 == 0)
    {
        printf("The answer is 0");
        return;
    }
    poly *h3 = (poly *)malloc(sizeof(poly));
    h3->coeff = h1->coeff * h2->coeff;
    h3->expo = h1->expo + h2->expo;
    h3->next = 0;
    poly *p = h1;
    poly *q = h2;
    q = h2->next; // first element of q is already been multiplied with first of p now required to mul the rest of q with p1 and so on
    poly *t = h3;
    while (p)
    {
        while (q)
        {
            t->next = (poly *)malloc(sizeof(poly));
            t = t->next;
            t->next = 0;
            t->coeff = p->coeff * q->coeff;
            t->expo = p->expo + q->expo;
            q = q->next;
        }
        p = p->next;
        q = h2; // q is again initialsed to the first of h2 because we need to multiply every p with all qs
    }
    h3 = prune_and_sort(h3);
    printf("First polynomial : ");
    display(h1);
    printf("Second polynomial : ");
    display(h2);
    printf("Multiplication of polynomials: ");
    display(h3);
    clear(h3);
}
// poly *add(poly *h1, poly *h2)
// {
//     poly *z;
//     if (h1 == 0 && h2 == 0)
//     {
//         printf("The polynomials are empty");
//         return 0;
//     }
//     if (h1 == NULL)
//         return copylist(h2);
//     if (h2 == NULL)
//         return copylist(h1);

//     // this h3 will be the head of the added polynomial
//     poly* h3 = 0;
//     poly *t = (poly *)malloc(sizeof(poly *));
//     // poly *t = h3;
//     // t->next = 0;
//     while (h1 && h2)
//     {
//         if (h1->expo > h2->expo)
//         {
//             t->expo = h1->expo;
//             t->coeff = h1->coeff;
//             h1 = h1->next;
//         }
//         else if (h1->expo < h2->expo)
//         {
//             t->expo = h2->expo;
//             t->coeff = h2->coeff;
//             h2 = h2->next;
//         }
//         else
//         {                       // when both the exponents match
//             t->expo = h1->expo; // or h2->expo
//             t->coeff = h1->coeff + h2->coeff;
//             h1 = h1->next;
//             h2 = h2->next;
//         }
//         if (h1 && h2)
//         {
//             t->next = (poly *)malloc(sizeof(poly *));
//             t = t->next;
//             t->next = 0;
//         }
//     }
//     if (h1)
//     {
//         z = h1;
//     }
//     else
//     {
//         z = h2;
//     }
//     poly *h4 = copylist(z);
//     t->next = h4;
//     return h3;
// }
int main()
{
    poly *h1 = 0, *h2 = 0, *h3 = 0;
    int choice;

    while (1)
    {
        printf("\n1. Add data for polynomial 1");
        printf("\n2. Add data for polynomia 2");
        printf("\n3. Display polynomial 1");
        printf("\n4. Display polynomial 2");
        printf("\n5.Prune and sort polynomial 1");
        printf("\n6.Prune and sort polynomial 2");
        printf("\n7. Add both the polynomials and see the result");
        printf("\n8. Subtract the polynomials");
        printf("\n9. Multiply the polynomials");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            h1 = addfirst(h1);
            break;
        case 2:
            h2 = addfirst(h2);
            break;
        case 3:
            display(h1);
            break;
        case 4:
            display(h2);
            break;
        case 5:
            prune_and_sort(h1);
            break;
        case 6:
            prune_and_sort(h2);
            break;
        case 7:
            add(h1, h2);
            break;
        case 8:
            subtract(h1, h2);
            break;
        case 9:
            multiply(h1, h2);
            break;
        default:
            printf("Thanks a lot!");
            exit(0);
        }
    }

    return 0;
}
